// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from project_interfaces:action/Patrol.idl
// generated code does not contain a copyright notice

#ifndef PROJECT_INTERFACES__ACTION__DETAIL__PATROL__STRUCT_H_
#define PROJECT_INTERFACES__ACTION__DETAIL__PATROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'targets'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in action/Patrol in the package project_interfaces.
typedef struct project_interfaces__action__Patrol_Goal
{
  geometry_msgs__msg__Point__Sequence targets;
} project_interfaces__action__Patrol_Goal;

// Struct for a sequence of project_interfaces__action__Patrol_Goal.
typedef struct project_interfaces__action__Patrol_Goal__Sequence
{
  project_interfaces__action__Patrol_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} project_interfaces__action__Patrol_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/Patrol in the package project_interfaces.
typedef struct project_interfaces__action__Patrol_Result
{
  rosidl_runtime_c__String result;
} project_interfaces__action__Patrol_Result;

// Struct for a sequence of project_interfaces__action__Patrol_Result.
typedef struct project_interfaces__action__Patrol_Result__Sequence
{
  project_interfaces__action__Patrol_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} project_interfaces__action__Patrol_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'feedback'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/Patrol in the package project_interfaces.
typedef struct project_interfaces__action__Patrol_Feedback
{
  rosidl_runtime_c__String feedback;
} project_interfaces__action__Patrol_Feedback;

// Struct for a sequence of project_interfaces__action__Patrol_Feedback.
typedef struct project_interfaces__action__Patrol_Feedback__Sequence
{
  project_interfaces__action__Patrol_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} project_interfaces__action__Patrol_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "project_interfaces/action/detail/patrol__struct.h"

/// Struct defined in action/Patrol in the package project_interfaces.
typedef struct project_interfaces__action__Patrol_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  project_interfaces__action__Patrol_Goal goal;
} project_interfaces__action__Patrol_SendGoal_Request;

// Struct for a sequence of project_interfaces__action__Patrol_SendGoal_Request.
typedef struct project_interfaces__action__Patrol_SendGoal_Request__Sequence
{
  project_interfaces__action__Patrol_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} project_interfaces__action__Patrol_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Patrol in the package project_interfaces.
typedef struct project_interfaces__action__Patrol_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} project_interfaces__action__Patrol_SendGoal_Response;

// Struct for a sequence of project_interfaces__action__Patrol_SendGoal_Response.
typedef struct project_interfaces__action__Patrol_SendGoal_Response__Sequence
{
  project_interfaces__action__Patrol_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} project_interfaces__action__Patrol_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Patrol in the package project_interfaces.
typedef struct project_interfaces__action__Patrol_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} project_interfaces__action__Patrol_GetResult_Request;

// Struct for a sequence of project_interfaces__action__Patrol_GetResult_Request.
typedef struct project_interfaces__action__Patrol_GetResult_Request__Sequence
{
  project_interfaces__action__Patrol_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} project_interfaces__action__Patrol_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "project_interfaces/action/detail/patrol__struct.h"

/// Struct defined in action/Patrol in the package project_interfaces.
typedef struct project_interfaces__action__Patrol_GetResult_Response
{
  int8_t status;
  project_interfaces__action__Patrol_Result result;
} project_interfaces__action__Patrol_GetResult_Response;

// Struct for a sequence of project_interfaces__action__Patrol_GetResult_Response.
typedef struct project_interfaces__action__Patrol_GetResult_Response__Sequence
{
  project_interfaces__action__Patrol_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} project_interfaces__action__Patrol_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "project_interfaces/action/detail/patrol__struct.h"

/// Struct defined in action/Patrol in the package project_interfaces.
typedef struct project_interfaces__action__Patrol_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  project_interfaces__action__Patrol_Feedback feedback;
} project_interfaces__action__Patrol_FeedbackMessage;

// Struct for a sequence of project_interfaces__action__Patrol_FeedbackMessage.
typedef struct project_interfaces__action__Patrol_FeedbackMessage__Sequence
{
  project_interfaces__action__Patrol_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} project_interfaces__action__Patrol_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PROJECT_INTERFACES__ACTION__DETAIL__PATROL__STRUCT_H_
