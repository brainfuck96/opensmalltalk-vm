/* Automatically generated from Squeak on 27 June 2012 4:45:52 am 
   by VMMaker 4.9.5
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
/*  The virtual machine proxy definition */
#include "sqVirtualMachine.h"
/* Configuration options */
#include "sqConfig.h"
/* Platform specific definitions */
#include "sqPlatformSpecific.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
#undef EXPORT
// was #undef EXPORT(returnType) but screws NorCroft cc
#define EXPORT(returnType) static returnType
#endif
#include "JoystickTabletPlugin.h"

#include "sqMemoryAccess.h"


/*** Constants ***/

/*** Function Prototypes ***/
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
#pragma export on
EXPORT(sqInt) initialiseModule(void);
EXPORT(sqInt) primitiveGetTabletParameters(void);
EXPORT(sqInt) primitiveReadJoystick(void);
EXPORT(sqInt) primitiveReadTablet(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
EXPORT(sqInt) shutdownModule(void);
#pragma export off
/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"JoystickTabletPlugin 27 June 2012 (i)"
#else
	"JoystickTabletPlugin 27 June 2012 (e)"
#endif
;



/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

EXPORT(const char*) getModuleName(void) {
	return moduleName;
}

static sqInt halt(void) {
	;
}

EXPORT(sqInt) initialiseModule(void) {
	return joystickInit();
}


/*	Get information on the pen tablet attached to this machine. Fail if there is no tablet. If successful, the result is an array of integers; see the Smalltalk call on this primitive for its interpretation. */

EXPORT(sqInt) primitiveGetTabletParameters(void) {
	int *  resultPtr;
	sqInt result;
	sqInt resultSize;
	sqInt cursorIndex;

	cursorIndex = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	resultSize = tabletResultSize();
	result = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classBitmap(), resultSize);
	resultPtr = (int *) interpreterProxy->firstIndexableField(result);
	interpreterProxy->success(tabletGetParameters(cursorIndex, resultPtr));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, result);
	return null;
}


/*	Read an input word from the joystick with the given index. */

EXPORT(sqInt) primitiveReadJoystick(void) {
	sqInt index;
	sqInt _return_value;

	index = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	_return_value = interpreterProxy->positive32BitIntegerFor((joystickRead(index)));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}


/*	Get the current state of the cursor of the pen tablet specified by my argument. Fail if there is no tablet. If successful, the result is an array of integers; see the Smalltalk call on this primitive for its interpretation. */

EXPORT(sqInt) primitiveReadTablet(void) {
	int *  resultPtr;
	sqInt result;
	sqInt resultSize;
	sqInt cursorIndex;

	cursorIndex = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	resultSize = tabletResultSize();
	result = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classBitmap(), resultSize);
	resultPtr = (int *) interpreterProxy->firstIndexableField(result);
	interpreterProxy->success(tabletRead(cursorIndex, resultPtr));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, result);
	return null;
}


/*	Note: This is coded so that is can be run from Squeak. */

EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter) {
	sqInt ok;

	interpreterProxy = anInterpreter;
	ok = interpreterProxy->majorVersion() == VM_PROXY_MAJOR;
	if (ok == 0) {
		return 0;
	}
	ok = interpreterProxy->minorVersion() >= VM_PROXY_MINOR;
	return ok;
}

EXPORT(sqInt) shutdownModule(void) {
	return joystickShutdown();
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* JoystickTabletPlugin_exports[][3] = {
	{"JoystickTabletPlugin", "primitiveReadJoystick", (void*)primitiveReadJoystick},
	{"JoystickTabletPlugin", "primitiveReadTablet", (void*)primitiveReadTablet},
	{"JoystickTabletPlugin", "setInterpreter", (void*)setInterpreter},
	{"JoystickTabletPlugin", "shutdownModule", (void*)shutdownModule},
	{"JoystickTabletPlugin", "primitiveGetTabletParameters", (void*)primitiveGetTabletParameters},
	{"JoystickTabletPlugin", "initialiseModule", (void*)initialiseModule},
	{"JoystickTabletPlugin", "getModuleName", (void*)getModuleName},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

