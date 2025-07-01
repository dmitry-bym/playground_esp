#ifdef __cplusplus
extern "C" {
#endif

#include "connectors.h"
#include "ui_connectors.h"
#include "state_connector.h"

void connectors_init(void) {
    ui_connector_init();
    state_connector_init();
}

#ifdef __cplusplus
}
#endif
