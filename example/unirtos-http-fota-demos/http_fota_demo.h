/*****************************************************************/ /**
* @file http_fota_demo.h
* @brief
* @author larson.li@quectel.com
* @date 2025-05-26
*
* @copyright Copyright (c) 2023 Quectel Wireless Solution, Co., Ltd.
* All Rights Reserved. Quectel Wireless Solution Proprietary and Confidential.
*
* @par EDIT HISTORY FOR MODULE
* <table>
* <tr><th>Date <th>Version <th>Author <th>Description
* <tr><td>2025-05-26 <td>1.0 <td>larson.li <td> Init
* </table>
**********************************************************************/
#ifndef __HTTP_FOTA_DEMO_H__
#define __HTTP_FOTA_DEMO_H__
#include "qurl_code.h"
#include "qurl_def.h"
#include "qurl_api.h"
#include "qcm_file_api.h"
#include "qosa_fota.h"

/*===========================================================================
 *  Macro Definition
 ===========================================================================*/
#define CONFIG_UNIRTOS_HTTP_FOTA_DEMO_TASK_STACK_SIZE 8192                                          // Demo task stack size configuration
#define UNIR_HTTP_FOTA_DEMO_TASK_PRIO                 QOSA_PRIORITY_NORMAL                          // Demo task priority configuration
#define UNIR_FOTA_PATH                                "http://112.31.84.164:8300/Bob/fotatest.par"  // FOTA package path configuration
#define UNIR_FOTA_PAKET_NAME                          "unir_fota_package.bin"                       // FOTA package filename configuration
#define UNIR_FOTAUPL_URL_MAX_LEN                      256                                           // Define maximum length for FOTA upload filename

/*===========================================================================
  *  struct
  ===========================================================================*/
/**
 * @struct unir_fota_http_t
 * @brief Defines unir_fota_http_t structure type, used to store various states and configuration information during HTTP transmission.
 */
typedef struct
{
    qurl_core_t   http_hd;                             /*!< HTTP header core information. */
    int           http_mode;                           /*!< HTTP mode. */
    int           ssl_ctxid;                           /*!< SSL context ID. */
    char          file_name[UNIR_FOTAUPL_URL_MAX_LEN]; /*!< File name to download or upload. */
    Q_FILE        fd;                                  /*!< File descriptor for file operations. */
    int           pdp_id;                              /*!< PDP context ID for mobile network data connection. */
    int           sim_id;                              /*!< SIM card ID. */
    qosa_uint32_t time_out;                            /*!< Timeout duration, unit may be milliseconds. */
    qosa_uint32_t start_pos;                           /*!< Starting position for download or upload. */
    qosa_uint32_t dload_want_size;                     /*!< Expected download size. */
    qosa_uint32_t resume_dload_count;                  /*!< Resume download count, used to handle restart after download interruption. */
    qosa_uint32_t fs_free_size;                        /*!< File system free space size. */
    int           event_errcode;                       /*!< Event error code, used to record errors that occur during the process. */
    int           write_errcode;                       /*!< Write error code, records errors in write operations. */
    int           chunk_encode;                        /*!< Chunk encoding flag, used to handle HTTP chunked transfer. */
    int           first_flag;                          /*!< Flag indicating whether it's the first transmission. */
    qosa_fota_t  *fota_ptr;                            /*!< FOTA operation handle */
    qosa_uint32_t write_size;                          /*!< Actual write size */
    qosa_uint32_t total_recv_cnt;                      /*!< Current accumulated total write size */
} unir_fota_http_t;

/*===========================================================================
  *  Enum
  ===========================================================================*/
/**
 * @brief HTTP FOTA error code enumeration definition
 */
typedef enum
{
    //FOTA success
    UNIR_FOAT_SUCCESS = QOSA_OK,
    UNIR_FOTA_HTTP_ERROR_UNKNOWN,
} unir_fota_error_e;

/*===========================================================================
 *  Function Declaration
 ===========================================================================*/
void unir_http_fota_demo_init(void);

#endif /* __HTTP_FOTA_DEMO_H__ */
