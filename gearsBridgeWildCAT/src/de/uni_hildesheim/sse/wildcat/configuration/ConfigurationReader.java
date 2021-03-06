package de.uni_hildesheim.sse.wildcat.configuration;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.logging.Logger;

import javax.management.NotificationBroadcaster;
import javax.xml.XMLConstants;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import javax.xml.transform.sax.SAXSource;
import javax.xml.validation.Schema;
import javax.xml.validation.SchemaFactory;
import javax.xml.validation.Validator;

import org.ow2.wildcat.Context;
import org.ow2.wildcat.ContextException;
import org.xml.sax.Attributes;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

import de.uni_hildesheim.sse.functions.FunctionRegistry;
import de.uni_hildesheim.sse.functions.IFunction;
import de.uni_hildesheim.sse.functions.IIdentity;
import de.uni_hildesheim.sse.wildcat.launcher.GearsBridgeContextConstants;
import de.uni_hildesheim.sse.wildcat.sensors.Sensor;
import de.uni_hildesheim.sse.wildcat.services.AbstractWServiceData;
import de.uni_hildesheim.sse.wildcat.services.WIdentity;

/**
 * Defines an class for reading the configuration file for the instrumentation.
 * 
 * @author Stephan Dederichs
 * 
 * @since 1.00
 * @version 1.00
 */
public class ConfigurationReader extends DefaultHandler {

    /**
     * A {@link Map} for storing the class names and the instances of the
     * classes.
     * 
     * @since 1.00
     */
    private Map<String, AbstractWServiceData> classes = new HashMap<
        String, AbstractWServiceData>();

    /**
     * Stores an instance of {@link AbstractWServiceData}.
     * 
     * @since 1.00
     */
    private AbstractWServiceData clazz = null;

    /**
     * Stores the name of the class which will be displayed in the management
     * application.
     * 
     * @since 1.00
     */
    private String classDisplayName = null;

    /**
     * Stores the name of an attribute.
     * 
     * @since 1.00
     */
    private String attributeName = null;

    /**
     * Stores the type of an attribute in a string representation.
     * 
     * @since 1.00
     */
    private String attributeType = null;

    /**
     * Stores the name of a function.
     * 
     * @since 1.00
     */
    private String functionName = null;

    /**
     * Stores the description of a function.
     * 
     * @since 1.00
     */
    private String functionDescription = null;

    /**
     * Stores the {@link Context} for registering.
     * 
     * @since 1.00
     */
    private Context ctx;

    /**
     * Stores the {@link NotificationBroadcaster} where the
     * services will be registered.
     * 
     * @since 1.00
     */
    private NotificationBroadcaster broadcaster;
    
    /**
     * Stores the {@link Logger}.
     * 
     * @since 1.00
     */
    private Logger log;

    /**
     * Creates an instance of {@link ConfigurationReader}.
     * 
     * @param ctx The {@link Context}.
     * @param broadcaster The {@link NotificationBroadcaster} where to send 
     *                  notifications.
     * @param log For logging.
     * 
     * @since 1.00
     */
    public ConfigurationReader(Context ctx, 
            NotificationBroadcaster broadcaster, Logger log) {
        this.ctx = ctx;
        this.broadcaster = broadcaster;
        this.log = log;
        // adding standard function to the FunctionRegistry
        FunctionRegistry.attachStandardFunctions();
    }

    /**
     * Reads the configuration file.
     * 
     * @param path The path with the configuration file.
     * 
     * @since 1.00
     */
    public void readConfiguration(String path) {
        try {
            // Create new SAX-Parser
            SAXParserFactory factory = SAXParserFactory.newInstance();
            SAXParser saxParser = factory.newSAXParser();

            Schema schema = loadSchema("../gearsBridgeWildCAT/src/de/"
                + "uni_hildesheim/sse/wildcat/configuration/configuration.xsd");
            validateXml(schema, path);

            // Parse XML file
            saxParser.parse(path, this);
        } catch (FileNotFoundException e) {
            logMessage("Configuration file (" + path + ") could not be found.");
            logMessage("System will exit");
            System.exit(0);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * Creates a xml schema.
     * 
     * @param path The path where the schema file is.
     * 
     * @return The schema.
     * 
     * @throws SAXException SaxException
     */
    private Schema loadSchema(String path) throws SAXException {
        String language = XMLConstants.W3C_XML_SCHEMA_NS_URI;
        SchemaFactory factory = SchemaFactory.newInstance(language);
        return factory.newSchema(new File(path));
    }

    /**
     * Validates a given xml file with a given xml schema.
     * 
     * @param schema The schema for the xml file.
     * @param xmlPath The path to the xml file.
     * 
     * @throws SAXException SAXException
     * @throws IOException IOException
     * 
     * @since 1.00
     */
    private void validateXml(Schema schema, String xmlPath)
        throws SAXException, IOException {
        // creating a Validator instance
        Validator validator = schema.newValidator();

        // preparing the XML file as a SAX source
        SAXSource source = new SAXSource(new InputSource(
                new java.io.FileInputStream(xmlPath)));

        // validating the SAX source against the schema
        validator.validate(source);
    }

    @Override
    public void startElement(String namespaceURI, String localName,
            String qName, Attributes atts) throws SAXException {
        // Checking the new tags for some keywords
        if (qName.equals("addedfunction")) {
            // Adding additional function
            FunctionRegistry.attachFunction(atts.getValue(0), atts.getValue(1));
        } else if (qName.equals("class") && null == clazz) {
            try {
                // Creating the defined class via reflection
                Class<?> c = Class.forName(atts.getValue(0));
                clazz = (AbstractWServiceData) c.newInstance();
                classes.put(atts.getValue(0), clazz);
                classDisplayName = atts.getValue(1);
            } catch (ClassNotFoundException e) {
                logMessage("Class " + e.getMessage()
                        + " not found. This class will be skipped.");
            } catch (InstantiationException e) {
                e.printStackTrace();
            } catch (IllegalAccessException e) {
                e.printStackTrace();
            } catch (Exception e) {
                e.printStackTrace();
            }
        } else if (null == attributeName) {
            attributeName = atts.getValue(0);
            attributeType = atts.getValue(1);
        } else if (null == functionName) {
            functionName = atts.getValue(0);
            functionDescription = atts.getValue(1);
            // Getting function from registry (null if not in the registry)
            IFunction function = FunctionRegistry.getFunction(functionName);
            // Creating a new Identity for the function
            IIdentity identity = new WIdentity(clazz, attributeName,
                    attributeType, functionDescription);
            // Only if the function is in the registry
            if (null != function && null != clazz) {
                function.setIdentity(identity);
                clazz.addFunction(function);
            } else if (null == function) {
                logMessage("Function " + functionName + " not found.");
            }
        }
    }

    @Override
    public void endElement(String namespaceURI, String localName, String qName)
    {
        // Checking the new tags for some keywords
        if (qName.equals("function")) {
            functionName = null;
            functionDescription = null;
        } else if (qName.equals("attribute")) {
            attributeName = null;
            attributeType = null;
        } else if (qName.equals("class")) {
            if (null != clazz) {
                try {
                    // adding the class to the NotificationBroadcaster
                    broadcaster.addNotificationListener(clazz, null, null);
                    
                    // adding the resource to the context
                    ctx.createResource(GearsBridgeContextConstants.
                            GEARSBRIDGE_DATA_DOMAIN);

                    // creating a new sensor
                    Sensor gearsBridgeSensor = new Sensor(classDisplayName);
                    // adding the sensor to the class
                    clazz.setSensor(gearsBridgeSensor);

                    clazz.updateFunctionValues();
                    
                    // add attribute to the context
                    ctx.attachAttribute(
                            GearsBridgeContextConstants.GEARSBRIDGE_DATA_DOMAIN
                                + "#" + gearsBridgeSensor.getSensorName(),
                                    gearsBridgeSensor);
                    
                    clazz = null;
                } catch (ContextException e) {
                    logMessage("Error while creating and registering "
                            + "resources and attributes.");
                }
            }
        }
    }
    
    /**
     * Logs a message.
     * 
     * @param message The message to lock.
     * 
     * @since 1.00
     */
    private void logMessage(String message) {
        if (null != log) {
            log.info(message);
        } else {
            System.out.println(message);
        }
    }

}
