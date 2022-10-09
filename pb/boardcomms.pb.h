#ifndef PB_PB_BOARDCOMMS_PB_H_INCLUDED
#define PB_PB_BOARDCOMMS_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
typedef enum _C2AMsgType {
    C2AMsgType_PING = 0,
    C2AMsgType_DXDY = 1,
    C2AMsgType_LASER = 2
} C2AMsgType;

typedef enum _A2CMsgType {
    A2CMsgType_PING_R = 0,
    A2CMsgType_ACK = 1
} A2CMsgType;

/* Struct definitions */
typedef struct _ATMegaToCoral {
    C2AMsgType message_type;
    int32_t ack;
    bool has_ping_response;
    int32_t ping_response;
} ATMegaToCoral;

typedef struct _CoralToATMega {
    C2AMsgType message_type;
    bool has_dx;
    int32_t dx;
    bool has_dy;
    int32_t dy;
    bool has_pingnum;
    int32_t pingnum;
    bool has_laser_on;
    bool laser_on;
} CoralToATMega;


/* Helper constants for enums */
#define _C2AMsgType_MIN C2AMsgType_PING
#define _C2AMsgType_MAX C2AMsgType_LASER
#define _C2AMsgType_ARRAYSIZE ((C2AMsgType)(C2AMsgType_LASER+1))

#define _A2CMsgType_MIN A2CMsgType_PING_R
#define _A2CMsgType_MAX A2CMsgType_ACK
#define _A2CMsgType_ARRAYSIZE ((A2CMsgType)(A2CMsgType_ACK+1))

#define CoralToATMega_message_type_ENUMTYPE C2AMsgType

#define ATMegaToCoral_message_type_ENUMTYPE C2AMsgType


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define CoralToATMega_init_default               {_C2AMsgType_MIN, false, 0, false, 0, false, 0, false, 0}
#define ATMegaToCoral_init_default               {_C2AMsgType_MIN, 0, false, 0}
#define CoralToATMega_init_zero                  {_C2AMsgType_MIN, false, 0, false, 0, false, 0, false, 0}
#define ATMegaToCoral_init_zero                  {_C2AMsgType_MIN, 0, false, 0}

/* Field tags (for use in manual encoding/decoding) */
#define ATMegaToCoral_message_type_tag           1
#define ATMegaToCoral_ack_tag                    2
#define ATMegaToCoral_ping_response_tag          3
#define CoralToATMega_message_type_tag           1
#define CoralToATMega_dx_tag                     2
#define CoralToATMega_dy_tag                     3
#define CoralToATMega_pingnum_tag                4
#define CoralToATMega_laser_on_tag               5

/* Struct field encoding specification for nanopb */
#define CoralToATMega_FIELDLIST(X, a) \
X(a, STATIC,   REQUIRED, UENUM,    message_type,      1) \
X(a, STATIC,   OPTIONAL, INT32,    dx,                2) \
X(a, STATIC,   OPTIONAL, INT32,    dy,                3) \
X(a, STATIC,   OPTIONAL, INT32,    pingnum,           4) \
X(a, STATIC,   OPTIONAL, BOOL,     laser_on,          5)
#define CoralToATMega_CALLBACK NULL
#define CoralToATMega_DEFAULT NULL

#define ATMegaToCoral_FIELDLIST(X, a) \
X(a, STATIC,   REQUIRED, UENUM,    message_type,      1) \
X(a, STATIC,   REQUIRED, INT32,    ack,               2) \
X(a, STATIC,   OPTIONAL, INT32,    ping_response,     3)
#define ATMegaToCoral_CALLBACK NULL
#define ATMegaToCoral_DEFAULT NULL

extern const pb_msgdesc_t CoralToATMega_msg;
extern const pb_msgdesc_t ATMegaToCoral_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define CoralToATMega_fields &CoralToATMega_msg
#define ATMegaToCoral_fields &ATMegaToCoral_msg

/* Maximum encoded size of messages (where known) */
#define ATMegaToCoral_size                       24
#define CoralToATMega_size                       37

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
