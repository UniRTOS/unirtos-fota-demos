/*****************************************************************/ /**
* @file ftp_fota_demo.h
* @brief FTP FOTA Demo Header File
* @author larson.li@quectel.com
* @date 2025-05-26
*
* @copyright Copyright (c) 2023 Quectel Wireless Solution, Co., Ltd.
* All Rights Reserved. Quectel Wireless Solution Proprietary and Confidential.
*
* @par EDIT HISTORY FOR MODULE
* <table>
* <tr><th>Date <th>Version <th>Author <th>Description
* <tr><td>2025-05-26 <td>1.0 <td>larson.li <td> Initial version
* </table>
**********************************************************************/
#ifndef __FTP_FOTA_DEMO_H__
#define __FTP_FOTA_DEMO_H__

#include "qcm_file_api.h"
#include "qurl_code.h"
#include "qurl_def.h"

/*===========================================================================
 *  Macro Definition
 ===========================================================================*/
#define CONFIG_UNIRTOS_FTP_FOTA_DEMO_TASK_STACK_SIZE 8192                                                      // Demo task stack size configuration
#define UNIR_FTP_FOTA_DEMO_TASK_PRIO                 QOSA_PRIORITY_NORMAL                                      // Demo task priority configuration
#define UNIR_FOTA_PATH_NAME                          "ftp://test:test@112.31.84.164:8309/BOB/default_ftp.par"  // FOTA upgrade package path name configuration
#define UNIR_FOTA_URL                                "ftp://112.31.84.164:8309/BOB/default_ftp.par"            // FOTA upgrade URL configuration
#define UNIR_FOTA_PAKET_NAME                         "unir_fota_package.bin"                                   // FOTA upgrade package filename configuration
#define UNIR_FOTAUPL_URL_MAX_LEN                     256                                                       // FOTA upgrade URL maximum length configuration

/*===========================================================================
 * callback
===========================================================================*/
typedef qosa_size_t (*UNIR_FTP_FOTA_WRITE_CB)(void *ptr, qosa_size_t size, void *stream);

/*===========================================================================
  *  struct
  ===========================================================================*/
/**
 * @struct fota_ftp_info_t
 * @brief Defines the fota_ftp_info_t structure type, used to store FTP transmission related information during FOTA upgrade process.
 */
typedef struct
{
    int           sim_id;                              /*!< SIM card identifier */
    int           pdp_id;                              /*!< PDP context identifier */
    char          path_name[UNIR_FOTAUPL_URL_MAX_LEN]; /*!< File path name */
    char          file_name[QCM_FILE_MAX_PATH_LEN];    /*!< Locally stored file name */
    qosa_uint32_t current_dl_offset;                   /*!< Currently downloaded length in bytes */
    double        current_dl_len;                      /*!< Current length to download in bytes */
    int           error_code;                          /*!< Error code, used to indicate error status during transmission */
    qosa_fota_t  *fota_ptr;                            /*!< FOTA operation handle */
} fota_ftp_info_t;

/**
 * @struct unir_ftp_context_t
 * @brief Defines the unir_ftp_context_t structure type, used to store FTP connection and operation related configuration and status information.
 */
typedef struct
{
    qurl_core_t    qurl;                               /*!< URL core configuration information */
    qurl_tls_cfg_t qurl_tls_cfg;                       /*!< TLS security configuration information */
    char           hostname[UNIR_FOTAUPL_URL_MAX_LEN]; /*!< FTP server hostname */
    char           username[UNIR_FOTAUPL_URL_MAX_LEN]; /*!< Username */
    char           password[UNIR_FOTAUPL_URL_MAX_LEN]; /*!< Password */
    int            timeout;                            /*!< Connection timeout time (seconds) */
    int            server_port;                        /*!< FTP server port number */
    int            ssl_enable;                         /*!< Encryption method */
    int            transfer;                           /*!< Data transfer mode */
    int            skip_pasv_ip;                       /*!< Whether to skip passive mode IP check */
    int            status;                             /*!< Current connection status */
    int            sslCtx;                             /*!< SSL context */
    int            pdp_cid;                            /*!< PDP context identifier */
    int            debug_enable;                       /*!< Debug function enable flag */
    int            ftp_port;                           /*!< FTP port mode, default uses passive mode UNIR_FTP_PASV_MODE */
    int            ipv6_extend;                        /*!< IPv6 extension function enable */
    int            last_reply_code;                    /*!< Last server response code */

    char *currentDir;                                  /*!< Current working directory */
    char *last_reply_Dir;                              /*!< Directory information in last response */
    char *server_ap;                                   /*!< FTP server absolute path */
} unir_ftp_context_t, *unir_ftp_context_ptr;

/**
 * @struct unir_ftp_fota_url_parts_t
 * @brief URL parsing result structure
 */
typedef struct
{
    char *username;   /*!< Username */
    char *password;   /*!< Password */
    char *server_url; /*!< Server URL */
    int   port;       /*!< Port number */
    char *file_path;  /*!< File path */
} unir_ftp_fota_url_parts_t;

/*===========================================================================
  *  Enum
  ===========================================================================*/
/**
 * @brief FTP FOTA error code enumeration definition
 */
typedef enum
{
    // FOTA success
    UNIR_FOAT_SUCCESS = QOSA_OK,
    UNIR_FOTA_FTP_ERROR_UNKNOWN,
} unir_fota_error_e;

/*===========================================================================
 *  Function Declaration
 ===========================================================================*/
void unir_ftp_fota_demo_init(void);

#endif /* __FTP_FOTA_DEMO_H__ */
