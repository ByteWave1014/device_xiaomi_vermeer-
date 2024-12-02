/*
 * Copyright (C) 2021-2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <libinit_dalvik_heap.h>
#include <libinit_variant.h>
#include <libinit_utils.h>

#include "vendor_init.h"

#define FINGERPRINT_GL "POCO/vermeer_global/vermeer:14/UKQ1.230804.001/V816.0.5.0.UNKMIXM:user/release-keys"
#define FINGERPRINT_CN "Redmi/vermeer/vermeer:14/UKQ1.230804.001/V816.0.18.0.DEV:user/release-keys"

static const variant_info_t vermeer_global_info = {
    .hwc_value = "GL",
    .sku_value = "",

    .brand = "POCO",
    .device = "vermeer",
    .marketname = "POCO F6 Pro",
    .model = "23113RKC6G",
    .mod_device = "vermeer_global",
    .build_fingerprint = FINGERPRINT_GL,
};

static const variant_info_t vermeer_info = {
    .hwc_value = "CN",
    .sku_value = "",

    .brand = "Xiaomi",
    .device = "vermeer",
    .marketname = "Redmi K70",
    .model = "23113RKC6C",
    .mod_device = "vermeer",
    .build_fingerprint = FINGERPRINT_CN,
};

static const std::vector<variant_info_t> variants = {
    vermeer_global_info,
    vermeer_info,
};

void vendor_load_properties() {
    set_dalvik_heap();
    search_variant(variants);

    // SafetyNet workaround
    property_override("ro.boot.verifiedbootstate", "green");
}
