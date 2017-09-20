#ifndef _H_CEVENT
#define _H_CEVENT
//typedef int (*free)(int n);

#include "cmemory.h"
#include "cobject.h"
#include "clinkedList.h"


#define CEVENT_NAME "eve"
#define CEVENT_OBSERVER_NAME "evo"
#define CEVENT_DISPATCHER_NAME "evd"

typedef void (*CEventFuncOnEvent)(CObject* context, CObject* args);

typedef struct {
  CObject parent;
  CObject *context;
  CEventFuncOnEvent onEvent;
} CEventObserver;

CEventObserver* newCEventObserver(CMemory*);
CEventObserver* initCEventObserver(CEventObserver* obj, CObject *context, CEventFuncOnEvent onEvent);


// UTF8
typedef struct {
  CObject parent;
  CLinkedList *observers;
} CEventDispatcher;

CEventDispatcher* newCEventDispatcher(CMemory*);
CEventDispatcher* initCEventDispatcher(CEventDispatcher* obj);
CEventObserver* ceventDispatcher_addListener(CEventDispatcher* obj, CObject*context, CEventFuncOnEvent);
CEventDispatcher* ceventDispatcher_removeListener(CEventDispatcher* obj, CEventObserver* target);
CEventDispatcher* ceventDispatcher_dispatch(CEventDispatcher* obj, CObject* event);
#endif