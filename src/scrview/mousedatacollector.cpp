#include "mousedatacollector.h"


MouseDataCollector::MouseDataCollector(QMutex* mutex, Server *server) {
    this->mutex = mutex;
    this->server = server;
    stoped = false;
}
