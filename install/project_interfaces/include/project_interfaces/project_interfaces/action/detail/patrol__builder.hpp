// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from project_interfaces:action/Patrol.idl
// generated code does not contain a copyright notice

#ifndef PROJECT_INTERFACES__ACTION__DETAIL__PATROL__BUILDER_HPP_
#define PROJECT_INTERFACES__ACTION__DETAIL__PATROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "project_interfaces/action/detail/patrol__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace project_interfaces
{

namespace action
{

namespace builder
{

class Init_Patrol_Goal_targets
{
public:
  Init_Patrol_Goal_targets()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::project_interfaces::action::Patrol_Goal targets(::project_interfaces::action::Patrol_Goal::_targets_type arg)
  {
    msg_.targets = std::move(arg);
    return std::move(msg_);
  }

private:
  ::project_interfaces::action::Patrol_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::project_interfaces::action::Patrol_Goal>()
{
  return project_interfaces::action::builder::Init_Patrol_Goal_targets();
}

}  // namespace project_interfaces


namespace project_interfaces
{

namespace action
{

namespace builder
{

class Init_Patrol_Result_result
{
public:
  Init_Patrol_Result_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::project_interfaces::action::Patrol_Result result(::project_interfaces::action::Patrol_Result::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::project_interfaces::action::Patrol_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::project_interfaces::action::Patrol_Result>()
{
  return project_interfaces::action::builder::Init_Patrol_Result_result();
}

}  // namespace project_interfaces


namespace project_interfaces
{

namespace action
{

namespace builder
{

class Init_Patrol_Feedback_feedback
{
public:
  Init_Patrol_Feedback_feedback()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::project_interfaces::action::Patrol_Feedback feedback(::project_interfaces::action::Patrol_Feedback::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::project_interfaces::action::Patrol_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::project_interfaces::action::Patrol_Feedback>()
{
  return project_interfaces::action::builder::Init_Patrol_Feedback_feedback();
}

}  // namespace project_interfaces


namespace project_interfaces
{

namespace action
{

namespace builder
{

class Init_Patrol_SendGoal_Request_goal
{
public:
  explicit Init_Patrol_SendGoal_Request_goal(::project_interfaces::action::Patrol_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::project_interfaces::action::Patrol_SendGoal_Request goal(::project_interfaces::action::Patrol_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::project_interfaces::action::Patrol_SendGoal_Request msg_;
};

class Init_Patrol_SendGoal_Request_goal_id
{
public:
  Init_Patrol_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Patrol_SendGoal_Request_goal goal_id(::project_interfaces::action::Patrol_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Patrol_SendGoal_Request_goal(msg_);
  }

private:
  ::project_interfaces::action::Patrol_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::project_interfaces::action::Patrol_SendGoal_Request>()
{
  return project_interfaces::action::builder::Init_Patrol_SendGoal_Request_goal_id();
}

}  // namespace project_interfaces


namespace project_interfaces
{

namespace action
{

namespace builder
{

class Init_Patrol_SendGoal_Response_stamp
{
public:
  explicit Init_Patrol_SendGoal_Response_stamp(::project_interfaces::action::Patrol_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::project_interfaces::action::Patrol_SendGoal_Response stamp(::project_interfaces::action::Patrol_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::project_interfaces::action::Patrol_SendGoal_Response msg_;
};

class Init_Patrol_SendGoal_Response_accepted
{
public:
  Init_Patrol_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Patrol_SendGoal_Response_stamp accepted(::project_interfaces::action::Patrol_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Patrol_SendGoal_Response_stamp(msg_);
  }

private:
  ::project_interfaces::action::Patrol_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::project_interfaces::action::Patrol_SendGoal_Response>()
{
  return project_interfaces::action::builder::Init_Patrol_SendGoal_Response_accepted();
}

}  // namespace project_interfaces


namespace project_interfaces
{

namespace action
{

namespace builder
{

class Init_Patrol_GetResult_Request_goal_id
{
public:
  Init_Patrol_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::project_interfaces::action::Patrol_GetResult_Request goal_id(::project_interfaces::action::Patrol_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::project_interfaces::action::Patrol_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::project_interfaces::action::Patrol_GetResult_Request>()
{
  return project_interfaces::action::builder::Init_Patrol_GetResult_Request_goal_id();
}

}  // namespace project_interfaces


namespace project_interfaces
{

namespace action
{

namespace builder
{

class Init_Patrol_GetResult_Response_result
{
public:
  explicit Init_Patrol_GetResult_Response_result(::project_interfaces::action::Patrol_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::project_interfaces::action::Patrol_GetResult_Response result(::project_interfaces::action::Patrol_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::project_interfaces::action::Patrol_GetResult_Response msg_;
};

class Init_Patrol_GetResult_Response_status
{
public:
  Init_Patrol_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Patrol_GetResult_Response_result status(::project_interfaces::action::Patrol_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Patrol_GetResult_Response_result(msg_);
  }

private:
  ::project_interfaces::action::Patrol_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::project_interfaces::action::Patrol_GetResult_Response>()
{
  return project_interfaces::action::builder::Init_Patrol_GetResult_Response_status();
}

}  // namespace project_interfaces


namespace project_interfaces
{

namespace action
{

namespace builder
{

class Init_Patrol_FeedbackMessage_feedback
{
public:
  explicit Init_Patrol_FeedbackMessage_feedback(::project_interfaces::action::Patrol_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::project_interfaces::action::Patrol_FeedbackMessage feedback(::project_interfaces::action::Patrol_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::project_interfaces::action::Patrol_FeedbackMessage msg_;
};

class Init_Patrol_FeedbackMessage_goal_id
{
public:
  Init_Patrol_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Patrol_FeedbackMessage_feedback goal_id(::project_interfaces::action::Patrol_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Patrol_FeedbackMessage_feedback(msg_);
  }

private:
  ::project_interfaces::action::Patrol_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::project_interfaces::action::Patrol_FeedbackMessage>()
{
  return project_interfaces::action::builder::Init_Patrol_FeedbackMessage_goal_id();
}

}  // namespace project_interfaces

#endif  // PROJECT_INTERFACES__ACTION__DETAIL__PATROL__BUILDER_HPP_
