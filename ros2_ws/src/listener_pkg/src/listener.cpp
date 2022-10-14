#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "custom_msgs/msg/coord.hpp"
using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
  public:
    MinimalSubscriber()
    : Node("minimal_subscriber")
    {
      subscription_ = this->create_subscription<custom_msgs::msg::Coord>(
      "chatter", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
    }

  private:
    void topic_callback(const custom_msgs::msg::Coord & msg) const
    {
      RCLCPP_INFO(this->get_logger(), "I heard: %d %d %d", msg.x, msg.y, msg.z);
    }
    rclcpp::Subscription<custom_msgs::msg::Coord>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
