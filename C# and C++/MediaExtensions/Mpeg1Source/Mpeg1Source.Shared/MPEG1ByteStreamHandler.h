//////////////////////////////////////////////////////////////////////////
//
// CMPEG1ByteStreamHandler.h
// Implements the byte-stream handler for the MPEG1 source.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//
//////////////////////////////////////////////////////////////////////////


#pragma once

//-------------------------------------------------------------------
// MPEG1ByteStreamHandler  class
//
// Byte-stream handler for MPEG-1 streams.
//-------------------------------------------------------------------

class CMPEG1ByteStreamHandler WrlSealed
    : public Microsoft::WRL::RuntimeClass<
        Microsoft::WRL::RuntimeClassFlags< Microsoft::WRL::RuntimeClassType::WinRtClassicComMix >, 
        ABI::Windows::Media::IMediaExtension,
        IMFByteStreamHandler 
        >
{
    InspectableClass(L"MPEG1Source.MPEG1ByteStreamHandler", BaseTrust)

public:
    CMPEG1ByteStreamHandler();
    virtual ~CMPEG1ByteStreamHandler();

    // IMediaExtension
    IFACEMETHOD (SetProperties) (ABI::Windows::Foundation::Collections::IPropertySet *pConfiguration);

    // IMFAsyncCallback
    STDMETHODIMP GetParameters(DWORD *pdwFlags, DWORD *pdwQueue)
    {
        // Implementation of this method is optional.
        return E_NOTIMPL;
    }

    // IMFByteStreamHandler
    STDMETHODIMP BeginCreateObject(
            /* [in] */ IMFByteStream *pByteStream,
            /* [in] */ LPCWSTR pwszURL,
            /* [in] */ DWORD dwFlags,
            /* [in] */ IPropertyStore *pProps,
            /* [out] */ IUnknown **ppIUnknownCancelCookie,
            /* [in] */ IMFAsyncCallback *pCallback,
            /* [in] */ IUnknown *punkState);

    STDMETHODIMP EndCreateObject(
            /* [in] */ IMFAsyncResult *pResult,
            /* [out] */ MF_OBJECT_TYPE *pObjectType,
            /* [out] */ IUnknown **ppObject);

    STDMETHODIMP CancelObjectCreation(IUnknown *pIUnknownCancelCookie);
    STDMETHODIMP GetMaxNumberOfBytesRequiredForResolution(QWORD *pqwBytes);
};
