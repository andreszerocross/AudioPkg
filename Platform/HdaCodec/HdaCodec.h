/*
 * File: HdaCodec.h
 *
 * Copyright (c) 2018 John Davis
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _EFI_HDA_CODEC_H_
#define _EFI_HDA_CODEC_H_

#include "AudioDxe.h"
#include "HdaVerbs.h"
#include "HdaCodecProtocol.h"

typedef struct _HDA_CODEC_DEV HDA_CODEC_DEV;
typedef struct _HDA_FUNC_GROUP HDA_FUNC_GROUP;

typedef struct {
    HDA_FUNC_GROUP *FuncGroup;
    UINT8 NodeId;
    UINT8 Type;

    // Capabilities.
    UINT32 Capabilities;
    UINT32 SupportedPcmRates;
    UINT32 SupportedFormats;
    UINT32 AmpInCapabilities;
    UINT32 AmpOutCapabilities;
    UINT32 PinCapabilities;
    UINT32 ConnectionListLength;
    UINT32 SupportedPowerStates;

} HDA_WIDGET;

struct _HDA_FUNC_GROUP {
    HDA_CODEC_DEV *HdaCodecDev;
    UINT8 NodeId;
    UINT8 Type;
    
    // Capabilities.
    UINT32 Capabilities;
    UINT32 SupportedPcmRates;
    UINT32 SupportedFormats;
    UINT32 AmpInCapabilities;
    UINT32 AmpOutCapabilities;
    UINT32 SupportedPowerStates;
    UINT32 GpioCapabilities;

    HDA_WIDGET *Widgets;
    UINT8 WidgetsCount;
};

struct _HDA_CODEC_DEV {
    // Protocols.
    EFI_HDA_CODEC_PROTOCOL *HdaCodecIo;
    EFI_DEVICE_PATH_PROTOCOL *DevicePath;

    // Codec information.
    UINT16 VendorId;
    UINT16 DeviceId;
    UINT8 RevisionId;
    UINT8 SteppindId;

    HDA_FUNC_GROUP *FuncGroups;
    UINTN FuncGroupsCount;
    UINT8 AudioFuncGroup;
};

EFI_STATUS
EFIAPI
HdaCodecPrintDefaults(
    HDA_CODEC_DEV *HdaCodecDev);

EFI_STATUS
EFIAPI
HdaCodecDriverBindingSupported(
    IN EFI_DRIVER_BINDING_PROTOCOL *This,
    IN EFI_HANDLE ControllerHandle,
    IN EFI_DEVICE_PATH_PROTOCOL *RemainingDevicePath OPTIONAL);

EFI_STATUS
EFIAPI
HdaCodecDriverBindingStart(
    IN EFI_DRIVER_BINDING_PROTOCOL *This,
    IN EFI_HANDLE ControllerHandle,
    IN EFI_DEVICE_PATH_PROTOCOL *RemainingDevicePath OPTIONAL);

EFI_STATUS
EFIAPI
HdaCodecDriverBindingStop(
    IN EFI_DRIVER_BINDING_PROTOCOL *This,
    IN EFI_HANDLE ControllerHandle,
    IN UINTN NumberOfChildren,
    IN EFI_HANDLE *ChildHandleBuffer OPTIONAL);

#endif
