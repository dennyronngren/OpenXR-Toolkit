/*******************************************************************************/
/*
Copyright (C) 2016 - 2020, Beijing 7invensun Technology Co.Ltd.All rights reserved.
Permission is hereby granted, free of charge, to any person or organization obtaining
a copy of the software and accompanying documentation covered by this license(the "Software")
to use, reproduce, display, distribute, execute, and transmit the Software, and to prepare
derivative works of the Software, and to permit third - parties to whom the Software
is furnished to do so, all subject to the following :
The copyright notices in the Software and this entire statement, including the above
license grant, this restriction and the following disclaimer, must be included in all
copies of the Software, in whole or in part, and all derivative works of the Software,
unless such copies or derivative works are solely in the form of machine - executable
object code generated by a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
PURPOSE, TITLE AND NON - INFRINGEMENT.IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR ANYONE
DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

@author 7invensun
*/
#ifndef _INCLUDE_7INVENSUN_ASEEVR_API_H_
#define _INCLUDE_7INVENSUN_ASEEVR_API_H_

#include "aSeeVRTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

    /** A callback function to receive asynchronous state from other APIs, registrates though aSeeVR_register_callback function.
    * @param state  A state(Refer to the definition of the aSeeVRState structure).
    * @param context  Used to pass the context of the caller, can be empty.
    * @return void
    */
	typedef void (_7INVENSUN_CALL *aSeeVR_state_callback)(const aSeeVRState* state, void* context);	

    /** A callback function to receive an eye image��registrates though aSeeVR_register_callback function.
    * @param image  Eye image data (Refer to the definition of the aSeeVRImage structure).
    * @param context  Used to pass the context of the caller, can be empty.
    * @return void
    */
	typedef void (_7INVENSUN_CALL *aSeeVR_eye_image_callback)(const aSeeVRImage* image, void* context);

    /** A callback function to receive eye featrues and gaze points, registrates though aSeeVR_register_callback function.

    * @param state   Eye data(Refer to the definition of the aSeeVREyeData structure).
    * @param context  Used to pass the context of the caller, can be empty.
    * @return void
    */
	typedef void (_7INVENSUN_CALL *aSeeVR_eye_data_callback)(const aSeeVREyeData* eye_data, void* context);

    /** A callback function for receiving the calibration coefficient, registrates though aSeeVR_register_callback function.
    * @param data  Calibration coefficient( Refer to the definition of the aSeeVRCoefficient structure).
    * @param context  Used to pass the context of the caller, can be empty.
    * @return void
    */
    typedef void (_7INVENSUN_CALL *aSeeVR_coefficient_callback)(const aSeeVRCoefficient* data, void* context);

    /** Registering Callback Function
    * @param type  Function type.
    * @param cb Callback function pointer.
    * @param context  Used to pass the context of the caller, can be empty.
    * @return  Refer to the definition of the aSeeVRReturnCode structure.
    */
	_7INVENSUN_API aSeeVRReturnCode _7INVENSUN_CALL aSeeVR_register_callback(aSeeVRCallbackType type, void* cb, void* context);

    /** Connect to the Server.
    * @param param  Initialization parameter(Refer to the definition of the aSeeVRImage structure).
    * @return  Refer to the definition of the aSeeVRReturnCode structure.
    */
	_7INVENSUN_API aSeeVRReturnCode _7INVENSUN_CALL aSeeVR_connect_server(const aSeeVRInitParam* param);

    /** Disconnect from the Server.
    * @param void
    * @return  Refer to the definition of the aSeeVRReturnCode structure.
    */
	_7INVENSUN_API aSeeVRReturnCode _7INVENSUN_CALL aSeeVR_disconnect_server(void);

    /** Start the device and start receiving data.
    * @param state  A state(param descriptive parameter)
    * @param context  Used to pass the context of the caller, can be empty.
    * @return  Refer to the definition in aSeeVRReturnCode.
    * @note  This function sends an asynchronous request to the server, and the return value only indicates whether the asynchronous request was successfully sent, whether the device is successfully stopped is returned asynchronously through the aSeeVR_state_callback function.
    * @pre  Function aSeeVR_connect_server has been called successfully, has successfully registered aSeeVR_state_callback through aSeeVR_register_callback.
    */
	_7INVENSUN_API aSeeVRReturnCode _7INVENSUN_CALL aSeeVR_start(const aSeeVRCoefficient* coe, const aSeeVRLanuchParam* others = 0);

    /** Halt Device.
    * @param void
    * @return  Refer to the definition of the aSeeVRReturnCode structure.
    * @note This function sends an asynchronous request to the server, and the return value only indicates whether the asynchronous request was successfully sent, whether the device is successfully stopped is returned asynchronously through the aSeeVR_state_callback function.
    * @pre Function aSeeVR_connect_server has been called successfully,has successfully registered aSeeVR_state_callback through aSeeVR_register_callback.
    */
	_7INVENSUN_API aSeeVRReturnCode _7INVENSUN_CALL aSeeVR_stop(void);

    /** Obtain Calibration Coefficient.
    * @param void
    * @return Refer to the definition of the aSeeVRReturnCode structure.
    * @note This function sends an asynchronous request to the server, and the return value only indicates whether the asynchronous request was successfully sent,calibration coefficient is returned by aSeeVR_coefficient_callback function asynchronously.
    * @pre Function aSeeVR_connect_server has been called successfully, has successfully registered aSeeVR_coefficient_callback through aSeeVR_register_callback.
    */
    _7INVENSUN_API aSeeVRReturnCode _7INVENSUN_CALL aSeeVR_get_coefficient(void);

#ifdef __cplusplus
}
#endif

#endif//_INCLUDE_7INVENSUN_ASEEVR_API_H_