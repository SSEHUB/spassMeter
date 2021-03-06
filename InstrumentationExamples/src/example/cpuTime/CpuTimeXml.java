package example.cpuTime;

import example.common.Data;

/**
 * Implements a simple memory allocation test.
 * 
 * @author Holger Eichelberger
 * @since 1.00
 * @version 1.00
 */
public class CpuTimeXml {

    /**
     * Defines the maximum allocation count.
     */
    private static final int MAX_ALLOC = 10000;

    /**
     * Stores the data.
     */
    private Data data;
    
    /**
     * Creates an instance of this test.
     * 
     * @since 1.00
     */
    private CpuTimeXml() {
        // enforce class loading
        data = new Data();
    }

    /**
     * Executes the test on this instance. Record this in an own monitoring 
     * group in order to avoid any overhead by class loading.
     * 
     * @since 1.00
     */
    private void execute() {
        // exclusion of short calls leads to smaller values in execute as the 
        // thread time tick resolution is too small
        for (int i = 0; i < MAX_ALLOC; i++) {
            data = new Data();
            if (i % 50 == 0) {
                System.gc();
            }
        }
    }
    
    /**
     * Returns the data.
     * 
     * @return the data
     */
    public Data getData() {
        return data;
    }
    
    /**
     * Starts the test.
     * 
     * @param args ignored
     * 
     * @since 1.00
     */
    public static void main(String[] args) {
        CpuTimeXml test = new CpuTimeXml();
        test.execute();
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
        }
    }

}
