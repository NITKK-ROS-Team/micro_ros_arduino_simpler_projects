#include <Arduino.h>

// microros definition =====================================================
#include "micro_ros_arduino_simpler/simpler_base.h"

#include <std_msgs/msg/int32.h>

// STM32F746NG -----------------------------------------------------------
#if not defined(ARDUINO_ARCH_STM32)
    #error "This example is only for STM32F746NG"
#endif

extern rclc_executor_t executor;
extern rclc_support_t support;
extern rcl_allocator_t allocator;
extern rcl_node_t node;

rcl_publisher_t publisher_0;
rcl_publisher_t publisher_1;
rcl_publisher_t publisher_2;
rcl_publisher_t publisher_3;
rcl_publisher_t publisher_4;
rcl_publisher_t publisher_5;

std_msgs__msg__Int32 msg_int32_0;
std_msgs__msg__Int32 msg_int32_1;
std_msgs__msg__Int32 msg_int32_2;
std_msgs__msg__Int32 msg_int32_3;
std_msgs__msg__Int32 msg_int32_4;
std_msgs__msg__Int32 msg_int32_5;

rcl_subscription_t subscription_0;
rcl_subscription_t subscription_1;
rcl_subscription_t subscription_2;
rcl_subscription_t subscription_3;
rcl_subscription_t subscription_4;

rcl_timer_t timer;
// ==========================================================================

int counter = 0;

// subscription callback ("/bool_data", "std_msgs/msg/bool") ================
void int32_callback_0(const void *msgin)
{
  const std_msgs__msg__Int32 *_msg = (const std_msgs__msg__Int32 *)msgin;
  msg_int32_0.data = _msg->data;
  rcl_publish(&publisher_1, &msg_int32_0, NULL);
}

void int32_callback_1(const void *msgin)
{
  const std_msgs__msg__Int32 *_msg = (const std_msgs__msg__Int32 *)msgin;
  msg_int32_1.data = _msg->data;
  rcl_publish(&publisher_2, &msg_int32_1, NULL);
}

void int32_callback_2(const void *msgin)
{
  const std_msgs__msg__Int32 *_msg = (const std_msgs__msg__Int32 *)msgin;
  msg_int32_2.data = _msg->data;
  rcl_publish(&publisher_3, &msg_int32_2, NULL);
}


void int32_callback_3(const void *msgin)
{
  const std_msgs__msg__Int32 *_msg = (const std_msgs__msg__Int32 *)msgin;
  msg_int32_3.data = _msg->data;
  rcl_publish(&publisher_4, &msg_int32_3, NULL);
}

void int32_callback_4(const void *msgin)
{
  const std_msgs__msg__Int32 *_msg = (const std_msgs__msg__Int32 *)msgin;
  msg_int32_4.data = _msg->data;
  rcl_publish(&publisher_5, &msg_int32_4, NULL);
}

// timer callback (10ms) ====================================================
void timer_callback(rcl_timer_t *timer, int64_t last_call_time)
{
  (void)last_call_time;
  (void)timer;

  counter++;

  msg_int32_0.data = counter;
  rcl_publish(&publisher_0, &msg_int32_0, NULL);
}

// setup micro_ros_arduino ===============================================
void setup()
{
  byte arduino_mac[] = {0xAA, 0xBB, 0xCC, 0xEE, 0xDD, 0xFF};
  IPAddress arduino_ip(192, 168, 0, 100);
  IPAddress agent_ip(192, 168, 0, 10);
  int agent_port = 2000;

  setup_microros_ethernet("uros_node", "ns", 6, arduino_mac, arduino_ip, agent_ip, agent_port);

  // rclc-publisher-subscriber-timer ======================================
  rclc_publisher_init_default(&publisher_0, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32), "int32_data_0");
  rclc_publisher_init_default(&publisher_1, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32), "int32_data_1");
  rclc_publisher_init_default(&publisher_2, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32), "int32_data_2");
  rclc_publisher_init_default(&publisher_3, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32), "int32_data_3");
  rclc_publisher_init_default(&publisher_4, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32), "int32_data_4");
  rclc_publisher_init_default(&publisher_5, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32), "int32_data_5");

  rclc_create_timer_and_add(&timer, 10, timer_callback);
  rclc_create_subscription_and_add(&subscription_0, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32), &msg_int32_0, &int32_callback_0, "int32_data_0");
  rclc_create_subscription_and_add(&subscription_1, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32), &msg_int32_1, &int32_callback_1, "int32_data_1");
  rclc_create_subscription_and_add(&subscription_2, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32), &msg_int32_2, &int32_callback_2, "int32_data_2");
  rclc_create_subscription_and_add(&subscription_3, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32), &msg_int32_3, &int32_callback_3, "int32_data_3");
  rclc_create_subscription_and_add(&subscription_4, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32), &msg_int32_4, &int32_callback_4, "int32_data_4");
}

// loop micro_ros_arduino ===============================================
void loop()
{
  rclc_delay(10);
}