#ifndef CLASSBINDING_H_
#define CLASSBINDING_H_

#include "Base.h"
#include "FunctionBinding.h"

/**
 * Represents the script binding for a class.
 */
struct ClassBinding
{
    /**
     * Constructor.
     * 
     * @param classname The name of the class.
     * @param refId The reference ID for the class (generated by Doxygen).
     */
    ClassBinding(string classname = "", string refId = "");

    /**
     * Writes out the generated Lua bindings in C++ to the given directory.
     * 
     * @param dir The directory to write the bindings files (.h and .cpp) to.
     * @param includes The includes for the class.
     * @param bindingNS The namespace to generate the Lua bindings within.
     */
    void write(string dir, const set<string>& includes, string* bindingNS = NULL);

    /** Holds all the public function bindings of the class. */
    map<string, vector<FunctionBinding> > bindings;
    /** Holds bindings for hidden functions of the class (protected/private). */
    map<string, vector<FunctionBinding> > hidden;
    /** Holds the name(s) of the derived class(es). */
    vector<string> derived;
    /** Holds the name of the class. */
    string classname;
    /** Holds the class's unique name (used only in the script bindings). */
    string uniquename;
    /** Holds the class's (Doxygen-generated) reference id. */
    string refId;
    /** Holds the needed include for the original class declaration. */
    string include;
    /** Holds whether the class has an inaccessible (protected/private) constructor (or has a pure-virtual method). */
    bool inaccessibleConstructor;
    /** Holds whether the class has an inaccessible (protected/private) destructor. */
    bool inaccessibleDestructor;
    /** Holds the class' namespace (if it has one). */
    string ns;
};

#endif