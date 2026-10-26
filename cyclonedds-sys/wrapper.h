#ifndef WRAPPER_H_
#define WRAPPER_H_

#include <dds/dds.h>
#include <dds/ddsc/dds_public_impl.h>
#include <dds/ddsc/dds_public_qosdefs.h>
#include <dds/ddsi/ddsi_radmin.h>
#include <dds/ddsi/ddsi_serdata.h>
#include <dds/ddsi/ddsi_sertype.h>

// XTypes / type library headers.
#include <dds/ddsi/ddsi_typewrap.h>
#include <dds/ddsi/ddsi_xt_typeinfo.h>
#include <dds/ddsi/ddsi_typelib.h>

// Wrapper Functions:
//
// Inline functions can't be processed in a sensible fashion by `bindgen`. Such
// functions that need to be accessed are wrapped here with the
// `_bindgen_wrapper` suffix. The `build.rs` strips these suffixes out when
// generating the binding and remaps the underlying symbol.  As a result, these
// functions can be accessed on Rust side without the `_bindgen_wrapper` suffix.
//
// If the function they wrap is not inline and the wrapper has the same name
// this will lead to a failure in compilation as duplicate symbols will be
// present at link time. This is desirable as the wrappers may be added safely
// for the inline functions and if they change downstream to no longer be inline
// the wrapper function may simply be removed.

/// Increments the reference count of a `ddsi_serdata` object.
static struct ddsi_serdata* ddsi_serdata_ref_bindgen_wrapper(
    const struct ddsi_serdata* serdata_const) {
  return ddsi_serdata_ref(serdata_const);
}

/// Decrements the reference count of a `ddsi_serdata` object.
static void ddsi_serdata_unref_bindgen_wrapper(struct ddsi_serdata* serdata) {
  ddsi_serdata_unref(serdata);
}

/// Returns the size of the serialised representation of a `ddsi_serdata`.
static uint32_t ddsi_serdata_size_bindgen_wrapper(
    const struct ddsi_serdata* serdata) {
  return ddsi_serdata_size(serdata);
}

/// Copies (part of) the serialised representation of a `ddsi_serdata` into a
/// caller provided buffer.
static void ddsi_serdata_to_ser_bindgen_wrapper(
    const struct ddsi_serdata* serdata, size_t off, size_t sz, void* buf) {
  ddsi_serdata_to_ser(serdata, off, sz, buf);
}

/// Provides a reference to the serialised representation of a `ddsi_serdata`
/// without copying. Must be released with `ddsi_serdata_to_ser_unref`.
///
/// NOTE `ddsrt_iovec_t` is the portable name: it maps to `struct iovec` on
/// POSIX and to `struct ddsrt_iovec` on Windows.
static struct ddsi_serdata* ddsi_serdata_to_ser_ref_bindgen_wrapper(
    const struct ddsi_serdata* serdata, size_t off, size_t sz,
    ddsrt_iovec_t* ref) {
  return ddsi_serdata_to_ser_ref(serdata, off, sz, ref);
}

/// Releases a reference previously obtained via `ddsi_serdata_to_ser_ref`.
static void ddsi_serdata_to_ser_unref_bindgen_wrapper(
    struct ddsi_serdata* serdata, const ddsrt_iovec_t* ref) {
  ddsi_serdata_to_ser_unref(serdata, ref);
}

/// Creates a `ddsi_serdata` from a serialised representation.
static struct ddsi_serdata* ddsi_serdata_from_ser_bindgen_wrapper(
    const struct ddsi_sertype* type, enum ddsi_serdata_kind kind,
    const struct ddsi_rdata* fragchain, size_t size) {
  return ddsi_serdata_from_ser(type, kind, fragchain, size);
}

/// Creates a `ddsi_serdata` from a serialised representation held in an iovec.
static struct ddsi_serdata* ddsi_serdata_from_ser_iov_bindgen_wrapper(
    const struct ddsi_sertype* type, enum ddsi_serdata_kind kind,
    ddsrt_msg_iovlen_t niov, const ddsrt_iovec_t* iov, size_t size) {
  return ddsi_serdata_from_ser_iov(type, kind, niov, iov, size);
}

/// Creates a `ddsi_serdata` from an application sample.
static struct ddsi_serdata* ddsi_serdata_from_sample_bindgen_wrapper(
    const struct ddsi_sertype* type, enum ddsi_serdata_kind kind,
    const void* sample) {
  return ddsi_serdata_from_sample(type, kind, sample);
}

/// Turns a `ddsi_serdata` into an application sample.
static bool ddsi_serdata_to_sample_bindgen_wrapper(
    const struct ddsi_serdata* serdata, void* sample, void** bufptr,
    void* buflim) {
  return ddsi_serdata_to_sample(serdata, sample, bufptr, buflim);
}

/// Extracts the key hash from a `ddsi_serdata` into `keyhash`.
static void ddsi_serdata_get_keyhash_bindgen_wrapper(
    const struct ddsi_serdata* serdata, struct ddsi_keyhash* buf,
    bool force_md5) {
  ddsi_serdata_get_keyhash(serdata, buf, force_md5);
}

/// Compares the keys of two `ddsi_serdata` objects.
static bool ddsi_serdata_eqkey_bindgen_wrapper(
    const struct ddsi_serdata* a, const struct ddsi_serdata* b) {
  return ddsi_serdata_eqkey(a, b);
}

/// Renders a `ddsi_serdata` as human readable text into `buf`.
static size_t ddsi_serdata_print_bindgen_wrapper(
    const struct ddsi_serdata* serdata, char* buf, size_t size) {
  return ddsi_serdata_print(serdata, buf, size);
}

/// The value that represents the default domain ID.
static const dds_domainid_t DOMAIN_DEFAULT = DDS_DOMAIN_DEFAULT;
/// The value that represents an infinite duration.
static const dds_duration_t DURATION_INFINITE = DDS_INFINITY;
/// The value that represents a time that is not reachable.
static const dds_time_t TIME_NEVER = DDS_NEVER;
/// Pseudo topic for the DcpsParticipant builtin topic.
static const dds_entity_t BUILTIN_TOPIC_DCPS_PARTICIPANT =
    DDS_BUILTIN_TOPIC_DCPSPARTICIPANT;
/// Pseudo topic for the DcpsTopic builtin topic.
///
/// NOTE this only works when Cyclone is built with `ENABLE_TOPIC_DISCOVERY`
/// enabled.
static const dds_entity_t BUILTIN_TOPIC_DCPS_TOPIC =
    DDS_BUILTIN_TOPIC_DCPSTOPIC;
/// Pseudo topic for the DcpsPublication builtin topic.
static const dds_entity_t BUILTIN_TOPIC_DCPS_PUBLICATION =
    DDS_BUILTIN_TOPIC_DCPSPUBLICATION;
/// Pseudo topic for the DcpsSubscription builtin topic.
static const dds_entity_t BUILTIN_TOPIC_DCPS_SUBSCRIPTION =
    DDS_BUILTIN_TOPIC_DCPSSUBSCRIPTION;

#endif  // WRAPPER_H_
