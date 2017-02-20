//
// Created by mirko on 19.02.17.
//

#ifndef LABOR_SWE_2_RUNNABLE_H
#define LABOR_SWE_2_RUNNABLE_H

class IRunnable {
public:
/**
* Perform startup actions in thread context.
* This method will be called precisely once, within the thread context,
* prior to the call to the 'run' method of this IRBRunnable
* object. This allows the IRBRunnable to perform any init operations
* that may be required within the execution context of the thread.
*/
    virtual void init (void) = 0;

/**
* Perform the work of this thread
* This method will be called to perform the work of the IRBRunnable
* object. This method is not expected to return until either the work
* of the thread is completed, or until the stop() method of this
* object has been called.
*/
    virtual void run (void) = 0;

/**
* Trigger a shutdown of this thread.
* The run() method is expected to react to this call by exiting. This
* method may not be called from within the thread context, for that
* reason cleanup operations are done separately (see the cleanup method).
*/
    virtual void stop (void) = 0;

/**
* Perform cleanup actions within the thread context.
* This method is called immediately following the exit from the run()
* method, within the thread context. This is where cleanup actions
* for this thread should be performed.
*/
    virtual void cleanup (void) = 0;

/**
* request to the component to prepare the necessary steps due to
* possible shutdown
*/
    virtual void prepareForShutdown (void) = 0;

/**
* request for resume.
*/
    virtual void reRun () = 0;

/* request: the component should go to the standby mode
*/
    virtual void goToStandby () = 0;
};

#endif //LABOR_SWE_2_RUNNABLE_H
