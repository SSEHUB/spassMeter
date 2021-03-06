package de.uni_hildesheim.sse.monitoring.runtime.configuration.xml;

/**
 * Defines a path element.
 * 
 * @author Holger Eichelberger
 * @since 1.00
 * @version 1.11
 */
class PathElement {
    
    /**
     * Defines member path element types.
     * 
     * @author Holger Eichelberger
     * @since 1.00
     * @version 1.00
     */
    public enum Type {
    
        /**
         * Denotes a namespace (package).
         */
        NAMESPACE("namespace", false),

        /**
         * Denotes a module (class).
         */
        MODULE("module", false),
        
        /**
         * Denotes a behavior (method).
         */
        BEHVIOUR("behavior", true),
        
        /**
         * Denotes a data element (attribute).
         */
        DATA("data", true);

        /**
         * Stores the name of the type in an XML file.
         */
        private String xmlName;

        /**
         * Stores whether the type denotes a class member.
         * 
         * @since 1.11
         */
        private boolean member;
        
        /**
         * Creates a new type constant.
         * 
         * @param xmlName the name of the type in an XML file
         * @param member whether this type denotes a member
         * 
         * @since 1.00
         */
        private Type(String xmlName, boolean member) {
            assert null != xmlName;
            this.xmlName = xmlName;
            this.member = member;
        }
        
        /**
         * Returns the name of this type in an XML file.
         * 
         * @return the name
         * 
         * @since 1.00
         */
        public String getXmlName() {
            return xmlName;
        }
        
        /**
         * Returns whether this type denotes a member.
         * 
         * @return <code>true</code> if it denotes a member, <code>false</code>
         *   else
         * 
         * @since 1.11
         */
        public boolean isMember() {
            return member;
        }
        
        /**
         * Returns the type matching (exactly) the given XML name.
         * 
         * @param name the XML name to search for
         * @return the matching type or <b>null</b> if none matches
         * 
         * @since 1.00
         */
        public static Type xmlValueOf(String name) {
            Type[] all = values();
            Type result = null;
            for (int i = 0; null == result && i < all.length; i++) {
                if (all[i].getXmlName().equals(name)) {
                    result = all[i];
                }
            }
            return result;
        }
    }
    
    /**
     * Stores the path element type.
     */
    private Type type;
    
    /**
     * Stores the name of the path element.
     */
    private String name;
    
    /**
     * Stores if this element is a pattern.
     */
    private String pattern;
    
    /**
     * Creates a new path element.
     * 
     * @param type the type of the path element
     * @param name the name of the element
     * @param pattern the pattern (if available, or <b>null</b>)
     * 
     * @since 1.00
     */
    public PathElement(Type type, String name, String pattern) {
        this.type = type;
        this.name = name;
        this.pattern = pattern;
    }
    
    /**
     * Returns the name of the path element.
     * 
     * @return the name
     * 
     * @since 1.00
     */
    public String getName() {
        return name;
    }
    
    /**
     * Returns the type of the path element.
     * 
     * @return the type
     * 
     * @since 1.00
     */
    public Type getType() {
        return type;
    }
    
    /**
     * Returns the pattern.
     * 
     * @return the pattern or <b>null</b>
     * 
     * @since 1.00
     */
    public String getPattern() {
        return pattern;
    }
    
    /**
     * Returns a textual description of this path element (for debugging).
     * 
     * @return a textual description
     */
    public String toString() {
        return "(" + name + " " + type + ")";
    }
        
}