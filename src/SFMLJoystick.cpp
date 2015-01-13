// -*- C++ -*-
/*!
 * @file  SFMLJoystick.cpp
 * @brief Joystick Component using SFML Library
 * @date $Date$
 *
 * @author Sugar Sweet Robotics
 *
 * LGPL
 *
 * $Id$
 */

#include "SFMLJoystick.h"

// Module specification
// <rtc-template block="module_spec">
static const char* sfmljoystick_spec[] =
  {
    "implementation_id", "SFMLJoystick",
    "type_name",         "SFMLJoystick",
    "description",       "Joystick Component using SFML Library",
    "version",           "1.0.0",
    "vendor",            "Sugar Sweet Robotics",
    "category",          "Input",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "15",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.debug", "0",
    "conf.default.id", "0",
    "conf.default.buttonOutputStyle", "event",
    // Widget
    "conf.__widget__.debug", "text",
    "conf.__widget__.id", "text",
    "conf.__widget__.buttonOutputStyle", "spin",
    // Constraints
    "conf.__constraints__.buttonOutputStyle", "event, continuous",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
SFMLJoystick::SFMLJoystick(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_axisOut("axis", m_axis),
    m_buttonsOut("buttons", m_buttons)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
SFMLJoystick::~SFMLJoystick()
{
}



RTC::ReturnCode_t SFMLJoystick::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("axis", m_axisOut);
  addOutPort("buttons", m_buttonsOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("debug", m_debug, "0");
  bindParameter("id", m_id, "0");
  bindParameter("buttonOutputStyle", m_buttonOutputStyle, "event");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SFMLJoystick::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SFMLJoystick::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SFMLJoystick::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t SFMLJoystick::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SFMLJoystick::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SFMLJoystick::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SFMLJoystick::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SFMLJoystick::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SFMLJoystick::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SFMLJoystick::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SFMLJoystick::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void SFMLJoystickInit(RTC::Manager* manager)
  {
    coil::Properties profile(sfmljoystick_spec);
    manager->registerFactory(profile,
                             RTC::Create<SFMLJoystick>,
                             RTC::Delete<SFMLJoystick>);
  }
  
};


