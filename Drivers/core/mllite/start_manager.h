/*
 $License:
    Copyright (C) 2011-2012 InvenSense Corporation, All Rights Reserved.
    See included License.txt for License information.
 $
 */

#include <string.h>
#include "log.h"

#ifndef INV_START_MANAGER_H__
#define INV_START_MANAGER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "mltypes.h"

/** Max number of start callbacks we can handle. */
#define INV_MAX_START_CB 20

  
typedef inv_error_t (*inv_start_cb_func)(void);
struct inv_start_cb_t {
    int num_cb;
    inv_start_cb_func start_cb[INV_MAX_START_CB];
};
  
inv_error_t inv_init_start_manager(void);
inv_error_t inv_register_mpl_start_notification(inv_error_t (*start_cb)(void));
inv_error_t inv_execute_mpl_start_notification(void);
inv_error_t inv_unregister_mpl_start_notification(inv_error_t (*start_cb)(void));

#ifdef __cplusplus
}
#endif
#endif  // INV_START_MANAGER_H__