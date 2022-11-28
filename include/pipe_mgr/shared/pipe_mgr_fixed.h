/*
 * Copyright(c) 2022 Intel Corporation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*!
 * @file pipe_mgr_counters.h
 *
 * @description Utilities for counters
 */

#ifndef __FF_MGR_FUNCT_H__
#define __FF_MGR_FUNCT_H__

#include <bf_types/bf_types.h>
#include <fixed_function/fixed_function_int.h>
#include <tdi/common/tdi_defs.h>
#include <tdi_rt/tdi_rt_defs.h>
#include <tdi_rt/c_frontend/tdi_rt_attributes.h>

typedef pipe_status_t (*fixed_func_mgr_update_callback)(
		dev_target_t dev_tgt,
		tdi_rt_attributes_type_e __attr_type,
		void *cookie,
		void *notif_data);
/**
 * API to install an entry into a fixed table
 *
 * @param  sess_hdl     Session handle.
 * @param  dev_tgt      Device target.
 * @param  table_name   table name
 * @param  key_spec     key spec
 * @return              Status of the API call
 */
int ff_mgr_ent_add(u32 sess_hdl,
                   struct bf_dev_target_t dev_tgt,
                   const char *table_name,
                   struct fixed_function_key_spec  *key_spec,
                   struct fixed_function_data_spec *data_spec);

/**
 * API to delete an entry
 *
 * @param  sess_hdl     Session handle.
 * @param  dev_tgt      Device target.
 * @param  table_name   table name
 * @param  key_spec     key spec
 * @return              Status of the API call
 */
int ff_mgr_ent_del(u32 sess_hdl,
                   struct bf_dev_target_t dev_tgt,
                   const char *table_name,
                   struct fixed_function_key_spec  *key_spec);

/**
 * API to get default entry for key less table
 *
 * @param  sess_hdl     Session handle.
 * @param  dev_tgt      Device target.
 * @param  table_name   table name
 * @param  data_spec    data spec to fill in return value
 * @return              Status of the API call
 */
int ff_mgr_ent_get_default_entry(u32 sess_hdl,
                                 struct bf_dev_target_t dev_tgt,
                                 const char *table_name,
                                 struct fixed_function_data_spec *data_spec);


/**
 * API to register auto notification
 *
 * @param  dev_tgt      Device target.
 * @param  table_name   table name
 * @param  call_back    C++ fixed func call back API
 * @param  _attr_type   TDI Attribute type
 * @param  void ptr     void pointer to callback cookie
 * @return              Status of the API call
 */
int fixed_func_mgr_notification_register(struct bf_dev_target_t dev_tgt,
                                         const char *table_name,
                                         fixed_func_mgr_update_callback cb,
                                         tdi_rt_attributes_type_e _attr_type,
                                         void *cb_cookie);

#endif /* __FF_MGR_FUNCT_H__ */
