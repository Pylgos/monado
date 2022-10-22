/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.7-dev */

#ifndef PB_MONADO_METRICS_MONADO_METRICS_PB_H_INCLUDED
#define PB_MONADO_METRICS_MONADO_METRICS_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
typedef struct _monado_metrics_SessionFrame {
    int64_t session_id;
    int64_t frame_id;
    uint64_t predicted_frame_time_ns;
    uint64_t predicted_wake_up_time_ns;
    uint64_t predicted_gpu_done_time_ns;
    uint64_t predicted_display_time_ns;
    uint64_t predicted_display_period_ns;
    uint64_t display_time_ns;
    uint64_t when_predicted_ns;
    uint64_t when_wait_woke_ns;
    uint64_t when_begin_ns;
    uint64_t when_delivered_ns;
    uint64_t when_gpu_done_ns;
    bool discarded;
} monado_metrics_SessionFrame;

typedef struct _monado_metrics_SystemFrame {
    int64_t frame_id;
    uint64_t predicted_display_time_ns;
    uint64_t predicted_display_period_ns;
    uint64_t desired_present_time_ns;
    uint64_t wake_up_time_ns;
    uint64_t present_slop_ns;
} monado_metrics_SystemFrame;

typedef struct _monado_metrics_SystemGpuInfo {
    int64_t frame_id;
    uint64_t gpu_start_ns;
    uint64_t gpu_end_ns;
    uint64_t when_ns;
} monado_metrics_SystemGpuInfo;

typedef struct _monado_metrics_SystemPresentInfo {
    int64_t frame_id;
    uint64_t expected_comp_time_ns;
    uint64_t predicted_wake_up_time_ns;
    uint64_t predicted_done_time_ns;
    uint64_t predicted_display_time_ns;
    uint64_t when_predict_ns;
    uint64_t when_woke_ns;
    uint64_t when_began_ns;
    uint64_t when_submitted_ns;
    uint64_t when_infoed_ns;
    uint64_t desired_present_time_ns;
    uint64_t present_slop_ns;
    uint64_t present_margin_ns;
    uint64_t actual_present_time_ns;
    uint64_t earliest_present_time_ns;
} monado_metrics_SystemPresentInfo;

typedef struct _monado_metrics_Used {
    int64_t session_id;
    int64_t session_frame_id;
    int64_t system_frame_id;
    uint64_t when_ns;
} monado_metrics_Used;

typedef struct _monado_metrics_Version {
    uint32_t major;
    uint32_t minor;
} monado_metrics_Version;

typedef struct _monado_metrics_Record {
    pb_size_t which_record;
    union {
        monado_metrics_Version version;
        monado_metrics_SessionFrame session_frame;
        monado_metrics_Used used;
        monado_metrics_SystemFrame system_frame;
        monado_metrics_SystemGpuInfo system_gpu_info;
        monado_metrics_SystemPresentInfo system_present_info;
    } record;
} monado_metrics_Record;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define monado_metrics_Version_init_default      {0, 0}
#define monado_metrics_SessionFrame_init_default {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define monado_metrics_Used_init_default         {0, 0, 0, 0}
#define monado_metrics_SystemFrame_init_default  {0, 0, 0, 0, 0, 0}
#define monado_metrics_SystemGpuInfo_init_default {0, 0, 0, 0}
#define monado_metrics_SystemPresentInfo_init_default {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define monado_metrics_Record_init_default       {0, {monado_metrics_Version_init_default}}
#define monado_metrics_Version_init_zero         {0, 0}
#define monado_metrics_SessionFrame_init_zero    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define monado_metrics_Used_init_zero            {0, 0, 0, 0}
#define monado_metrics_SystemFrame_init_zero     {0, 0, 0, 0, 0, 0}
#define monado_metrics_SystemGpuInfo_init_zero   {0, 0, 0, 0}
#define monado_metrics_SystemPresentInfo_init_zero {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define monado_metrics_Record_init_zero          {0, {monado_metrics_Version_init_zero}}

/* Field tags (for use in manual encoding/decoding) */
#define monado_metrics_SessionFrame_session_id_tag 1
#define monado_metrics_SessionFrame_frame_id_tag 2
#define monado_metrics_SessionFrame_predicted_frame_time_ns_tag 3
#define monado_metrics_SessionFrame_predicted_wake_up_time_ns_tag 4
#define monado_metrics_SessionFrame_predicted_gpu_done_time_ns_tag 5
#define monado_metrics_SessionFrame_predicted_display_time_ns_tag 6
#define monado_metrics_SessionFrame_predicted_display_period_ns_tag 7
#define monado_metrics_SessionFrame_display_time_ns_tag 8
#define monado_metrics_SessionFrame_when_predicted_ns_tag 9
#define monado_metrics_SessionFrame_when_wait_woke_ns_tag 10
#define monado_metrics_SessionFrame_when_begin_ns_tag 11
#define monado_metrics_SessionFrame_when_delivered_ns_tag 12
#define monado_metrics_SessionFrame_when_gpu_done_ns_tag 13
#define monado_metrics_SessionFrame_discarded_tag 14
#define monado_metrics_SystemFrame_frame_id_tag  1
#define monado_metrics_SystemFrame_predicted_display_time_ns_tag 2
#define monado_metrics_SystemFrame_predicted_display_period_ns_tag 3
#define monado_metrics_SystemFrame_desired_present_time_ns_tag 4
#define monado_metrics_SystemFrame_wake_up_time_ns_tag 5
#define monado_metrics_SystemFrame_present_slop_ns_tag 6
#define monado_metrics_SystemGpuInfo_frame_id_tag 1
#define monado_metrics_SystemGpuInfo_gpu_start_ns_tag 2
#define monado_metrics_SystemGpuInfo_gpu_end_ns_tag 3
#define monado_metrics_SystemGpuInfo_when_ns_tag 4
#define monado_metrics_SystemPresentInfo_frame_id_tag 1
#define monado_metrics_SystemPresentInfo_expected_comp_time_ns_tag 2
#define monado_metrics_SystemPresentInfo_predicted_wake_up_time_ns_tag 3
#define monado_metrics_SystemPresentInfo_predicted_done_time_ns_tag 4
#define monado_metrics_SystemPresentInfo_predicted_display_time_ns_tag 5
#define monado_metrics_SystemPresentInfo_when_predict_ns_tag 6
#define monado_metrics_SystemPresentInfo_when_woke_ns_tag 7
#define monado_metrics_SystemPresentInfo_when_began_ns_tag 8
#define monado_metrics_SystemPresentInfo_when_submitted_ns_tag 9
#define monado_metrics_SystemPresentInfo_when_infoed_ns_tag 10
#define monado_metrics_SystemPresentInfo_desired_present_time_ns_tag 11
#define monado_metrics_SystemPresentInfo_present_slop_ns_tag 12
#define monado_metrics_SystemPresentInfo_present_margin_ns_tag 13
#define monado_metrics_SystemPresentInfo_actual_present_time_ns_tag 14
#define monado_metrics_SystemPresentInfo_earliest_present_time_ns_tag 15
#define monado_metrics_Used_session_id_tag       1
#define monado_metrics_Used_session_frame_id_tag 2
#define monado_metrics_Used_system_frame_id_tag  3
#define monado_metrics_Used_when_ns_tag          4
#define monado_metrics_Version_major_tag         1
#define monado_metrics_Version_minor_tag         2
#define monado_metrics_Record_version_tag        1
#define monado_metrics_Record_session_frame_tag  2
#define monado_metrics_Record_used_tag           3
#define monado_metrics_Record_system_frame_tag   4
#define monado_metrics_Record_system_gpu_info_tag 5
#define monado_metrics_Record_system_present_info_tag 6

/* Struct field encoding specification for nanopb */
#define monado_metrics_Version_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   major,             1) \
X(a, STATIC,   SINGULAR, UINT32,   minor,             2)
#define monado_metrics_Version_CALLBACK NULL
#define monado_metrics_Version_DEFAULT NULL

#define monado_metrics_SessionFrame_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT64,    session_id,        1) \
X(a, STATIC,   SINGULAR, INT64,    frame_id,          2) \
X(a, STATIC,   SINGULAR, UINT64,   predicted_frame_time_ns,   3) \
X(a, STATIC,   SINGULAR, UINT64,   predicted_wake_up_time_ns,   4) \
X(a, STATIC,   SINGULAR, UINT64,   predicted_gpu_done_time_ns,   5) \
X(a, STATIC,   SINGULAR, UINT64,   predicted_display_time_ns,   6) \
X(a, STATIC,   SINGULAR, UINT64,   predicted_display_period_ns,   7) \
X(a, STATIC,   SINGULAR, UINT64,   display_time_ns,   8) \
X(a, STATIC,   SINGULAR, UINT64,   when_predicted_ns,   9) \
X(a, STATIC,   SINGULAR, UINT64,   when_wait_woke_ns,  10) \
X(a, STATIC,   SINGULAR, UINT64,   when_begin_ns,    11) \
X(a, STATIC,   SINGULAR, UINT64,   when_delivered_ns,  12) \
X(a, STATIC,   SINGULAR, UINT64,   when_gpu_done_ns,  13) \
X(a, STATIC,   SINGULAR, BOOL,     discarded,        14)
#define monado_metrics_SessionFrame_CALLBACK NULL
#define monado_metrics_SessionFrame_DEFAULT NULL

#define monado_metrics_Used_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT64,    session_id,        1) \
X(a, STATIC,   SINGULAR, INT64,    session_frame_id,   2) \
X(a, STATIC,   SINGULAR, INT64,    system_frame_id,   3) \
X(a, STATIC,   SINGULAR, UINT64,   when_ns,           4)
#define monado_metrics_Used_CALLBACK NULL
#define monado_metrics_Used_DEFAULT NULL

#define monado_metrics_SystemFrame_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT64,    frame_id,          1) \
X(a, STATIC,   SINGULAR, UINT64,   predicted_display_time_ns,   2) \
X(a, STATIC,   SINGULAR, UINT64,   predicted_display_period_ns,   3) \
X(a, STATIC,   SINGULAR, UINT64,   desired_present_time_ns,   4) \
X(a, STATIC,   SINGULAR, UINT64,   wake_up_time_ns,   5) \
X(a, STATIC,   SINGULAR, UINT64,   present_slop_ns,   6)
#define monado_metrics_SystemFrame_CALLBACK NULL
#define monado_metrics_SystemFrame_DEFAULT NULL

#define monado_metrics_SystemGpuInfo_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT64,    frame_id,          1) \
X(a, STATIC,   SINGULAR, UINT64,   gpu_start_ns,      2) \
X(a, STATIC,   SINGULAR, UINT64,   gpu_end_ns,        3) \
X(a, STATIC,   SINGULAR, UINT64,   when_ns,           4)
#define monado_metrics_SystemGpuInfo_CALLBACK NULL
#define monado_metrics_SystemGpuInfo_DEFAULT NULL

#define monado_metrics_SystemPresentInfo_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT64,    frame_id,          1) \
X(a, STATIC,   SINGULAR, UINT64,   expected_comp_time_ns,   2) \
X(a, STATIC,   SINGULAR, UINT64,   predicted_wake_up_time_ns,   3) \
X(a, STATIC,   SINGULAR, UINT64,   predicted_done_time_ns,   4) \
X(a, STATIC,   SINGULAR, UINT64,   predicted_display_time_ns,   5) \
X(a, STATIC,   SINGULAR, UINT64,   when_predict_ns,   6) \
X(a, STATIC,   SINGULAR, UINT64,   when_woke_ns,      7) \
X(a, STATIC,   SINGULAR, UINT64,   when_began_ns,     8) \
X(a, STATIC,   SINGULAR, UINT64,   when_submitted_ns,   9) \
X(a, STATIC,   SINGULAR, UINT64,   when_infoed_ns,   10) \
X(a, STATIC,   SINGULAR, UINT64,   desired_present_time_ns,  11) \
X(a, STATIC,   SINGULAR, UINT64,   present_slop_ns,  12) \
X(a, STATIC,   SINGULAR, UINT64,   present_margin_ns,  13) \
X(a, STATIC,   SINGULAR, UINT64,   actual_present_time_ns,  14) \
X(a, STATIC,   SINGULAR, UINT64,   earliest_present_time_ns,  15)
#define monado_metrics_SystemPresentInfo_CALLBACK NULL
#define monado_metrics_SystemPresentInfo_DEFAULT NULL

#define monado_metrics_Record_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    MESSAGE,  (record,version,record.version),   1) \
X(a, STATIC,   ONEOF,    MESSAGE,  (record,session_frame,record.session_frame),   2) \
X(a, STATIC,   ONEOF,    MESSAGE,  (record,used,record.used),   3) \
X(a, STATIC,   ONEOF,    MESSAGE,  (record,system_frame,record.system_frame),   4) \
X(a, STATIC,   ONEOF,    MESSAGE,  (record,system_gpu_info,record.system_gpu_info),   5) \
X(a, STATIC,   ONEOF,    MESSAGE,  (record,system_present_info,record.system_present_info),   6)
#define monado_metrics_Record_CALLBACK NULL
#define monado_metrics_Record_DEFAULT NULL
#define monado_metrics_Record_record_version_MSGTYPE monado_metrics_Version
#define monado_metrics_Record_record_session_frame_MSGTYPE monado_metrics_SessionFrame
#define monado_metrics_Record_record_used_MSGTYPE monado_metrics_Used
#define monado_metrics_Record_record_system_frame_MSGTYPE monado_metrics_SystemFrame
#define monado_metrics_Record_record_system_gpu_info_MSGTYPE monado_metrics_SystemGpuInfo
#define monado_metrics_Record_record_system_present_info_MSGTYPE monado_metrics_SystemPresentInfo

extern const pb_msgdesc_t monado_metrics_Version_msg;
extern const pb_msgdesc_t monado_metrics_SessionFrame_msg;
extern const pb_msgdesc_t monado_metrics_Used_msg;
extern const pb_msgdesc_t monado_metrics_SystemFrame_msg;
extern const pb_msgdesc_t monado_metrics_SystemGpuInfo_msg;
extern const pb_msgdesc_t monado_metrics_SystemPresentInfo_msg;
extern const pb_msgdesc_t monado_metrics_Record_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define monado_metrics_Version_fields &monado_metrics_Version_msg
#define monado_metrics_SessionFrame_fields &monado_metrics_SessionFrame_msg
#define monado_metrics_Used_fields &monado_metrics_Used_msg
#define monado_metrics_SystemFrame_fields &monado_metrics_SystemFrame_msg
#define monado_metrics_SystemGpuInfo_fields &monado_metrics_SystemGpuInfo_msg
#define monado_metrics_SystemPresentInfo_fields &monado_metrics_SystemPresentInfo_msg
#define monado_metrics_Record_fields &monado_metrics_Record_msg

/* Maximum encoded size of messages (where known) */
#define monado_metrics_Record_size               168
#define monado_metrics_SessionFrame_size         145
#define monado_metrics_SystemFrame_size          66
#define monado_metrics_SystemGpuInfo_size        44
#define monado_metrics_SystemPresentInfo_size    165
#define monado_metrics_Used_size                 44
#define monado_metrics_Version_size              12

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
