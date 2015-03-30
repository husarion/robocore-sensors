/**
 ******************************************************************************
 * \file    Hitechnic_Gyro.h
 * \author  Husarion team
 * \version V0.9
 * \date    2-June-2014
 * \brief   Provides interface for Hitechnic Accelerometer sensor.
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

#ifndef __HITECHNIC_ACCEL_H__
#define __HITECHNIC_ACCEL_H__

#include <hFramework.h>

namespace hSensors
{
/**
 * @brief Provides interface for Hitechnic Accelerometer sensor.
 */
class Hitechnic_Accel
{
public:
	enum EError { ERROR_OK, ERROR_PROTO };

	/**
	 * @brief Create accelerometer object.
	 * @param i2c - I2C sensor (eg. hSens1.i2c, hSens2.i2c)
	 */
	Hitechnic_Accel(hI2C& i2c);
	/**
	 * @brief Create accelerometer object.
	 * @param sensor - I2C capable hSensor port (eg. hSens1, hSens2)
	 */
	Hitechnic_Accel(hSensor_i2c& sensor);
	~Hitechnic_Accel(); //!< Destory gyro object.

	void init(); //!< Initialize accelerometer.
	void deinit(); //! Deinitialize accelerometer.

	/**
	 * @brief Read raw acceleration data.
	 * @param x - x axis 
	 * @param y - y axis
	 * @param z - z axis
	 * @return error code
	 */
	EError readRaw(int16_t& x, int16_t& y, int16_t& z);

	/**
	 * @brief Read acceleration data.
	 * @param x - x axis in g
	 * @param y - y axiin gs
	 * @param z - z axiin gs
	 * @return error code
	 */
	EError read(float& x, float& y, float& z);

private:
	hI2C &i2c;
};

}

#endif