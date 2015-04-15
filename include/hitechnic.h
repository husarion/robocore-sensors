/**
 ******************************************************************************
 * \file    hitechnic.h
 * \author  Husarion team
 * \version V0.9
 * \date    2-June-2014
 * \brief   Provides interface for Hitechnic robotc-like API.
 ******************************************************************************
 * \details This file is part of robocore-sensors library.
 *
 * \copyright Copyright (C) 2014 Husarion Sp. z o.o. <husarion.com> - All Rights Reserved.
 * Unauthorized copying of this file and the robocore-sensors library,
 * via any medium is strictly prohibited. Proprietary and confidential.
 *
 * \attention
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 ******************************************************************************
 */

#ifndef __HITECHNIC_H__
#define __HITECHNIC_H__

#include <hFramework.h>

/**
 * @brief Provides interface for Hitechnic robotc-like API.
 */
class tHitechnicSensor
{
public:
	ISensor_i2c &sens;
	bool initialized;
	int mode;
	float param1;

	tHitechnicSensor(ISensor_i2c& sens) : sens(sens), initialized(false) { }
	~tHitechnicSensor()
	{
		deinit();
	}
	void deinit()
	{
		sens.selectGPIO();
		sens.getPinIntAdc().disableADC();
		sens.getPin1().setIn();
		sens.getPin2().setIn();
		initialized = false;
	}
};

#endif
