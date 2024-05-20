// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from project_interfaces:action/Patrol.idl
// generated code does not contain a copyright notice
#include "project_interfaces/action/detail/patrol__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `targets`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
project_interfaces__action__Patrol_Goal__init(project_interfaces__action__Patrol_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // targets
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->targets, 0)) {
    project_interfaces__action__Patrol_Goal__fini(msg);
    return false;
  }
  return true;
}

void
project_interfaces__action__Patrol_Goal__fini(project_interfaces__action__Patrol_Goal * msg)
{
  if (!msg) {
    return;
  }
  // targets
  geometry_msgs__msg__Point__Sequence__fini(&msg->targets);
}

bool
project_interfaces__action__Patrol_Goal__are_equal(const project_interfaces__action__Patrol_Goal * lhs, const project_interfaces__action__Patrol_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // targets
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->targets), &(rhs->targets)))
  {
    return false;
  }
  return true;
}

bool
project_interfaces__action__Patrol_Goal__copy(
  const project_interfaces__action__Patrol_Goal * input,
  project_interfaces__action__Patrol_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // targets
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->targets), &(output->targets)))
  {
    return false;
  }
  return true;
}

project_interfaces__action__Patrol_Goal *
project_interfaces__action__Patrol_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  project_interfaces__action__Patrol_Goal * msg = (project_interfaces__action__Patrol_Goal *)allocator.allocate(sizeof(project_interfaces__action__Patrol_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(project_interfaces__action__Patrol_Goal));
  bool success = project_interfaces__action__Patrol_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
project_interfaces__action__Patrol_Goal__destroy(project_interfaces__action__Patrol_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    project_interfaces__action__Patrol_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
project_interfaces__action__Patrol_Goal__Sequence__init(project_interfaces__action__Patrol_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  project_interfaces__action__Patrol_Goal * data = NULL;

  if (size) {
    data = (project_interfaces__action__Patrol_Goal *)allocator.zero_allocate(size, sizeof(project_interfaces__action__Patrol_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = project_interfaces__action__Patrol_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        project_interfaces__action__Patrol_Goal__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
project_interfaces__action__Patrol_Goal__Sequence__fini(project_interfaces__action__Patrol_Goal__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      project_interfaces__action__Patrol_Goal__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

project_interfaces__action__Patrol_Goal__Sequence *
project_interfaces__action__Patrol_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  project_interfaces__action__Patrol_Goal__Sequence * array = (project_interfaces__action__Patrol_Goal__Sequence *)allocator.allocate(sizeof(project_interfaces__action__Patrol_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = project_interfaces__action__Patrol_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
project_interfaces__action__Patrol_Goal__Sequence__destroy(project_interfaces__action__Patrol_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    project_interfaces__action__Patrol_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
project_interfaces__action__Patrol_Goal__Sequence__are_equal(const project_interfaces__action__Patrol_Goal__Sequence * lhs, const project_interfaces__action__Patrol_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!project_interfaces__action__Patrol_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
project_interfaces__action__Patrol_Goal__Sequence__copy(
  const project_interfaces__action__Patrol_Goal__Sequence * input,
  project_interfaces__action__Patrol_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(project_interfaces__action__Patrol_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    project_interfaces__action__Patrol_Goal * data =
      (project_interfaces__action__Patrol_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!project_interfaces__action__Patrol_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          project_interfaces__action__Patrol_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!project_interfaces__action__Patrol_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
#include "rosidl_runtime_c/string_functions.h"

bool
project_interfaces__action__Patrol_Result__init(project_interfaces__action__Patrol_Result * msg)
{
  if (!msg) {
    return false;
  }
  // result
  if (!rosidl_runtime_c__String__init(&msg->result)) {
    project_interfaces__action__Patrol_Result__fini(msg);
    return false;
  }
  return true;
}

void
project_interfaces__action__Patrol_Result__fini(project_interfaces__action__Patrol_Result * msg)
{
  if (!msg) {
    return;
  }
  // result
  rosidl_runtime_c__String__fini(&msg->result);
}

bool
project_interfaces__action__Patrol_Result__are_equal(const project_interfaces__action__Patrol_Result * lhs, const project_interfaces__action__Patrol_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
project_interfaces__action__Patrol_Result__copy(
  const project_interfaces__action__Patrol_Result * input,
  project_interfaces__action__Patrol_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  if (!rosidl_runtime_c__String__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

project_interfaces__action__Patrol_Result *
project_interfaces__action__Patrol_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  project_interfaces__action__Patrol_Result * msg = (project_interfaces__action__Patrol_Result *)allocator.allocate(sizeof(project_interfaces__action__Patrol_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(project_interfaces__action__Patrol_Result));
  bool success = project_interfaces__action__Patrol_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
project_interfaces__action__Patrol_Result__destroy(project_interfaces__action__Patrol_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    project_interfaces__action__Patrol_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
project_interfaces__action__Patrol_Result__Sequence__init(project_interfaces__action__Patrol_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  project_interfaces__action__Patrol_Result * data = NULL;

  if (size) {
    data = (project_interfaces__action__Patrol_Result *)allocator.zero_allocate(size, sizeof(project_interfaces__action__Patrol_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = project_interfaces__action__Patrol_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        project_interfaces__action__Patrol_Result__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
project_interfaces__action__Patrol_Result__Sequence__fini(project_interfaces__action__Patrol_Result__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      project_interfaces__action__Patrol_Result__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

project_interfaces__action__Patrol_Result__Sequence *
project_interfaces__action__Patrol_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  project_interfaces__action__Patrol_Result__Sequence * array = (project_interfaces__action__Patrol_Result__Sequence *)allocator.allocate(sizeof(project_interfaces__action__Patrol_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = project_interfaces__action__Patrol_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
project_interfaces__action__Patrol_Result__Sequence__destroy(project_interfaces__action__Patrol_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    project_interfaces__action__Patrol_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
project_interfaces__action__Patrol_Result__Sequence__are_equal(const project_interfaces__action__Patrol_Result__Sequence * lhs, const project_interfaces__action__Patrol_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!project_interfaces__action__Patrol_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
project_interfaces__action__Patrol_Result__Sequence__copy(
  const project_interfaces__action__Patrol_Result__Sequence * input,
  project_interfaces__action__Patrol_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(project_interfaces__action__Patrol_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    project_interfaces__action__Patrol_Result * data =
      (project_interfaces__action__Patrol_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!project_interfaces__action__Patrol_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          project_interfaces__action__Patrol_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!project_interfaces__action__Patrol_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `feedback`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
project_interfaces__action__Patrol_Feedback__init(project_interfaces__action__Patrol_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // feedback
  if (!rosidl_runtime_c__String__init(&msg->feedback)) {
    project_interfaces__action__Patrol_Feedback__fini(msg);
    return false;
  }
  return true;
}

void
project_interfaces__action__Patrol_Feedback__fini(project_interfaces__action__Patrol_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // feedback
  rosidl_runtime_c__String__fini(&msg->feedback);
}

bool
project_interfaces__action__Patrol_Feedback__are_equal(const project_interfaces__action__Patrol_Feedback * lhs, const project_interfaces__action__Patrol_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // feedback
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
project_interfaces__action__Patrol_Feedback__copy(
  const project_interfaces__action__Patrol_Feedback * input,
  project_interfaces__action__Patrol_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // feedback
  if (!rosidl_runtime_c__String__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

project_interfaces__action__Patrol_Feedback *
project_interfaces__action__Patrol_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  project_interfaces__action__Patrol_Feedback * msg = (project_interfaces__action__Patrol_Feedback *)allocator.allocate(sizeof(project_interfaces__action__Patrol_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(project_interfaces__action__Patrol_Feedback));
  bool success = project_interfaces__action__Patrol_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
project_interfaces__action__Patrol_Feedback__destroy(project_interfaces__action__Patrol_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    project_interfaces__action__Patrol_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
project_interfaces__action__Patrol_Feedback__Sequence__init(project_interfaces__action__Patrol_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  project_interfaces__action__Patrol_Feedback * data = NULL;

  if (size) {
    data = (project_interfaces__action__Patrol_Feedback *)allocator.zero_allocate(size, sizeof(project_interfaces__action__Patrol_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = project_interfaces__action__Patrol_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        project_interfaces__action__Patrol_Feedback__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
project_interfaces__action__Patrol_Feedback__Sequence__fini(project_interfaces__action__Patrol_Feedback__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      project_interfaces__action__Patrol_Feedback__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

project_interfaces__action__Patrol_Feedback__Sequence *
project_interfaces__action__Patrol_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  project_interfaces__action__Patrol_Feedback__Sequence * array = (project_interfaces__action__Patrol_Feedback__Sequence *)allocator.allocate(sizeof(project_interfaces__action__Patrol_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = project_interfaces__action__Patrol_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
project_interfaces__action__Patrol_Feedback__Sequence__destroy(project_interfaces__action__Patrol_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    project_interfaces__action__Patrol_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
project_interfaces__action__Patrol_Feedback__Sequence__are_equal(const project_interfaces__action__Patrol_Feedback__Sequence * lhs, const project_interfaces__action__Patrol_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!project_interfaces__action__Patrol_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
project_interfaces__action__Patrol_Feedback__Sequence__copy(
  const project_interfaces__action__Patrol_Feedback__Sequence * input,
  project_interfaces__action__Patrol_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(project_interfaces__action__Patrol_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    project_interfaces__action__Patrol_Feedback * data =
      (project_interfaces__action__Patrol_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!project_interfaces__action__Patrol_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          project_interfaces__action__Patrol_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!project_interfaces__action__Patrol_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "project_interfaces/action/detail/patrol__functions.h"

bool
project_interfaces__action__Patrol_SendGoal_Request__init(project_interfaces__action__Patrol_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    project_interfaces__action__Patrol_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!project_interfaces__action__Patrol_Goal__init(&msg->goal)) {
    project_interfaces__action__Patrol_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
project_interfaces__action__Patrol_SendGoal_Request__fini(project_interfaces__action__Patrol_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  project_interfaces__action__Patrol_Goal__fini(&msg->goal);
}

bool
project_interfaces__action__Patrol_SendGoal_Request__are_equal(const project_interfaces__action__Patrol_SendGoal_Request * lhs, const project_interfaces__action__Patrol_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!project_interfaces__action__Patrol_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
project_interfaces__action__Patrol_SendGoal_Request__copy(
  const project_interfaces__action__Patrol_SendGoal_Request * input,
  project_interfaces__action__Patrol_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!project_interfaces__action__Patrol_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

project_interfaces__action__Patrol_SendGoal_Request *
project_interfaces__action__Patrol_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  project_interfaces__action__Patrol_SendGoal_Request * msg = (project_interfaces__action__Patrol_SendGoal_Request *)allocator.allocate(sizeof(project_interfaces__action__Patrol_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(project_interfaces__action__Patrol_SendGoal_Request));
  bool success = project_interfaces__action__Patrol_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
project_interfaces__action__Patrol_SendGoal_Request__destroy(project_interfaces__action__Patrol_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    project_interfaces__action__Patrol_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
project_interfaces__action__Patrol_SendGoal_Request__Sequence__init(project_interfaces__action__Patrol_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  project_interfaces__action__Patrol_SendGoal_Request * data = NULL;

  if (size) {
    data = (project_interfaces__action__Patrol_SendGoal_Request *)allocator.zero_allocate(size, sizeof(project_interfaces__action__Patrol_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = project_interfaces__action__Patrol_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        project_interfaces__action__Patrol_SendGoal_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
project_interfaces__action__Patrol_SendGoal_Request__Sequence__fini(project_interfaces__action__Patrol_SendGoal_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      project_interfaces__action__Patrol_SendGoal_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

project_interfaces__action__Patrol_SendGoal_Request__Sequence *
project_interfaces__action__Patrol_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  project_interfaces__action__Patrol_SendGoal_Request__Sequence * array = (project_interfaces__action__Patrol_SendGoal_Request__Sequence *)allocator.allocate(sizeof(project_interfaces__action__Patrol_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = project_interfaces__action__Patrol_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
project_interfaces__action__Patrol_SendGoal_Request__Sequence__destroy(project_interfaces__action__Patrol_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    project_interfaces__action__Patrol_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
project_interfaces__action__Patrol_SendGoal_Request__Sequence__are_equal(const project_interfaces__action__Patrol_SendGoal_Request__Sequence * lhs, const project_interfaces__action__Patrol_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!project_interfaces__action__Patrol_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
project_interfaces__action__Patrol_SendGoal_Request__Sequence__copy(
  const project_interfaces__action__Patrol_SendGoal_Request__Sequence * input,
  project_interfaces__action__Patrol_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(project_interfaces__action__Patrol_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    project_interfaces__action__Patrol_SendGoal_Request * data =
      (project_interfaces__action__Patrol_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!project_interfaces__action__Patrol_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          project_interfaces__action__Patrol_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!project_interfaces__action__Patrol_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
project_interfaces__action__Patrol_SendGoal_Response__init(project_interfaces__action__Patrol_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    project_interfaces__action__Patrol_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
project_interfaces__action__Patrol_SendGoal_Response__fini(project_interfaces__action__Patrol_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
project_interfaces__action__Patrol_SendGoal_Response__are_equal(const project_interfaces__action__Patrol_SendGoal_Response * lhs, const project_interfaces__action__Patrol_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
project_interfaces__action__Patrol_SendGoal_Response__copy(
  const project_interfaces__action__Patrol_SendGoal_Response * input,
  project_interfaces__action__Patrol_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

project_interfaces__action__Patrol_SendGoal_Response *
project_interfaces__action__Patrol_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  project_interfaces__action__Patrol_SendGoal_Response * msg = (project_interfaces__action__Patrol_SendGoal_Response *)allocator.allocate(sizeof(project_interfaces__action__Patrol_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(project_interfaces__action__Patrol_SendGoal_Response));
  bool success = project_interfaces__action__Patrol_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
project_interfaces__action__Patrol_SendGoal_Response__destroy(project_interfaces__action__Patrol_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    project_interfaces__action__Patrol_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
project_interfaces__action__Patrol_SendGoal_Response__Sequence__init(project_interfaces__action__Patrol_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  project_interfaces__action__Patrol_SendGoal_Response * data = NULL;

  if (size) {
    data = (project_interfaces__action__Patrol_SendGoal_Response *)allocator.zero_allocate(size, sizeof(project_interfaces__action__Patrol_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = project_interfaces__action__Patrol_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        project_interfaces__action__Patrol_SendGoal_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
project_interfaces__action__Patrol_SendGoal_Response__Sequence__fini(project_interfaces__action__Patrol_SendGoal_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      project_interfaces__action__Patrol_SendGoal_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

project_interfaces__action__Patrol_SendGoal_Response__Sequence *
project_interfaces__action__Patrol_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  project_interfaces__action__Patrol_SendGoal_Response__Sequence * array = (project_interfaces__action__Patrol_SendGoal_Response__Sequence *)allocator.allocate(sizeof(project_interfaces__action__Patrol_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = project_interfaces__action__Patrol_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
project_interfaces__action__Patrol_SendGoal_Response__Sequence__destroy(project_interfaces__action__Patrol_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    project_interfaces__action__Patrol_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
project_interfaces__action__Patrol_SendGoal_Response__Sequence__are_equal(const project_interfaces__action__Patrol_SendGoal_Response__Sequence * lhs, const project_interfaces__action__Patrol_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!project_interfaces__action__Patrol_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
project_interfaces__action__Patrol_SendGoal_Response__Sequence__copy(
  const project_interfaces__action__Patrol_SendGoal_Response__Sequence * input,
  project_interfaces__action__Patrol_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(project_interfaces__action__Patrol_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    project_interfaces__action__Patrol_SendGoal_Response * data =
      (project_interfaces__action__Patrol_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!project_interfaces__action__Patrol_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          project_interfaces__action__Patrol_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!project_interfaces__action__Patrol_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
project_interfaces__action__Patrol_GetResult_Request__init(project_interfaces__action__Patrol_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    project_interfaces__action__Patrol_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
project_interfaces__action__Patrol_GetResult_Request__fini(project_interfaces__action__Patrol_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
project_interfaces__action__Patrol_GetResult_Request__are_equal(const project_interfaces__action__Patrol_GetResult_Request * lhs, const project_interfaces__action__Patrol_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
project_interfaces__action__Patrol_GetResult_Request__copy(
  const project_interfaces__action__Patrol_GetResult_Request * input,
  project_interfaces__action__Patrol_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

project_interfaces__action__Patrol_GetResult_Request *
project_interfaces__action__Patrol_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  project_interfaces__action__Patrol_GetResult_Request * msg = (project_interfaces__action__Patrol_GetResult_Request *)allocator.allocate(sizeof(project_interfaces__action__Patrol_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(project_interfaces__action__Patrol_GetResult_Request));
  bool success = project_interfaces__action__Patrol_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
project_interfaces__action__Patrol_GetResult_Request__destroy(project_interfaces__action__Patrol_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    project_interfaces__action__Patrol_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
project_interfaces__action__Patrol_GetResult_Request__Sequence__init(project_interfaces__action__Patrol_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  project_interfaces__action__Patrol_GetResult_Request * data = NULL;

  if (size) {
    data = (project_interfaces__action__Patrol_GetResult_Request *)allocator.zero_allocate(size, sizeof(project_interfaces__action__Patrol_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = project_interfaces__action__Patrol_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        project_interfaces__action__Patrol_GetResult_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
project_interfaces__action__Patrol_GetResult_Request__Sequence__fini(project_interfaces__action__Patrol_GetResult_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      project_interfaces__action__Patrol_GetResult_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

project_interfaces__action__Patrol_GetResult_Request__Sequence *
project_interfaces__action__Patrol_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  project_interfaces__action__Patrol_GetResult_Request__Sequence * array = (project_interfaces__action__Patrol_GetResult_Request__Sequence *)allocator.allocate(sizeof(project_interfaces__action__Patrol_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = project_interfaces__action__Patrol_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
project_interfaces__action__Patrol_GetResult_Request__Sequence__destroy(project_interfaces__action__Patrol_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    project_interfaces__action__Patrol_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
project_interfaces__action__Patrol_GetResult_Request__Sequence__are_equal(const project_interfaces__action__Patrol_GetResult_Request__Sequence * lhs, const project_interfaces__action__Patrol_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!project_interfaces__action__Patrol_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
project_interfaces__action__Patrol_GetResult_Request__Sequence__copy(
  const project_interfaces__action__Patrol_GetResult_Request__Sequence * input,
  project_interfaces__action__Patrol_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(project_interfaces__action__Patrol_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    project_interfaces__action__Patrol_GetResult_Request * data =
      (project_interfaces__action__Patrol_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!project_interfaces__action__Patrol_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          project_interfaces__action__Patrol_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!project_interfaces__action__Patrol_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "project_interfaces/action/detail/patrol__functions.h"

bool
project_interfaces__action__Patrol_GetResult_Response__init(project_interfaces__action__Patrol_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!project_interfaces__action__Patrol_Result__init(&msg->result)) {
    project_interfaces__action__Patrol_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
project_interfaces__action__Patrol_GetResult_Response__fini(project_interfaces__action__Patrol_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  project_interfaces__action__Patrol_Result__fini(&msg->result);
}

bool
project_interfaces__action__Patrol_GetResult_Response__are_equal(const project_interfaces__action__Patrol_GetResult_Response * lhs, const project_interfaces__action__Patrol_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!project_interfaces__action__Patrol_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
project_interfaces__action__Patrol_GetResult_Response__copy(
  const project_interfaces__action__Patrol_GetResult_Response * input,
  project_interfaces__action__Patrol_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!project_interfaces__action__Patrol_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

project_interfaces__action__Patrol_GetResult_Response *
project_interfaces__action__Patrol_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  project_interfaces__action__Patrol_GetResult_Response * msg = (project_interfaces__action__Patrol_GetResult_Response *)allocator.allocate(sizeof(project_interfaces__action__Patrol_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(project_interfaces__action__Patrol_GetResult_Response));
  bool success = project_interfaces__action__Patrol_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
project_interfaces__action__Patrol_GetResult_Response__destroy(project_interfaces__action__Patrol_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    project_interfaces__action__Patrol_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
project_interfaces__action__Patrol_GetResult_Response__Sequence__init(project_interfaces__action__Patrol_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  project_interfaces__action__Patrol_GetResult_Response * data = NULL;

  if (size) {
    data = (project_interfaces__action__Patrol_GetResult_Response *)allocator.zero_allocate(size, sizeof(project_interfaces__action__Patrol_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = project_interfaces__action__Patrol_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        project_interfaces__action__Patrol_GetResult_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
project_interfaces__action__Patrol_GetResult_Response__Sequence__fini(project_interfaces__action__Patrol_GetResult_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      project_interfaces__action__Patrol_GetResult_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

project_interfaces__action__Patrol_GetResult_Response__Sequence *
project_interfaces__action__Patrol_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  project_interfaces__action__Patrol_GetResult_Response__Sequence * array = (project_interfaces__action__Patrol_GetResult_Response__Sequence *)allocator.allocate(sizeof(project_interfaces__action__Patrol_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = project_interfaces__action__Patrol_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
project_interfaces__action__Patrol_GetResult_Response__Sequence__destroy(project_interfaces__action__Patrol_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    project_interfaces__action__Patrol_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
project_interfaces__action__Patrol_GetResult_Response__Sequence__are_equal(const project_interfaces__action__Patrol_GetResult_Response__Sequence * lhs, const project_interfaces__action__Patrol_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!project_interfaces__action__Patrol_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
project_interfaces__action__Patrol_GetResult_Response__Sequence__copy(
  const project_interfaces__action__Patrol_GetResult_Response__Sequence * input,
  project_interfaces__action__Patrol_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(project_interfaces__action__Patrol_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    project_interfaces__action__Patrol_GetResult_Response * data =
      (project_interfaces__action__Patrol_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!project_interfaces__action__Patrol_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          project_interfaces__action__Patrol_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!project_interfaces__action__Patrol_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "project_interfaces/action/detail/patrol__functions.h"

bool
project_interfaces__action__Patrol_FeedbackMessage__init(project_interfaces__action__Patrol_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    project_interfaces__action__Patrol_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!project_interfaces__action__Patrol_Feedback__init(&msg->feedback)) {
    project_interfaces__action__Patrol_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
project_interfaces__action__Patrol_FeedbackMessage__fini(project_interfaces__action__Patrol_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  project_interfaces__action__Patrol_Feedback__fini(&msg->feedback);
}

bool
project_interfaces__action__Patrol_FeedbackMessage__are_equal(const project_interfaces__action__Patrol_FeedbackMessage * lhs, const project_interfaces__action__Patrol_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!project_interfaces__action__Patrol_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
project_interfaces__action__Patrol_FeedbackMessage__copy(
  const project_interfaces__action__Patrol_FeedbackMessage * input,
  project_interfaces__action__Patrol_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!project_interfaces__action__Patrol_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

project_interfaces__action__Patrol_FeedbackMessage *
project_interfaces__action__Patrol_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  project_interfaces__action__Patrol_FeedbackMessage * msg = (project_interfaces__action__Patrol_FeedbackMessage *)allocator.allocate(sizeof(project_interfaces__action__Patrol_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(project_interfaces__action__Patrol_FeedbackMessage));
  bool success = project_interfaces__action__Patrol_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
project_interfaces__action__Patrol_FeedbackMessage__destroy(project_interfaces__action__Patrol_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    project_interfaces__action__Patrol_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
project_interfaces__action__Patrol_FeedbackMessage__Sequence__init(project_interfaces__action__Patrol_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  project_interfaces__action__Patrol_FeedbackMessage * data = NULL;

  if (size) {
    data = (project_interfaces__action__Patrol_FeedbackMessage *)allocator.zero_allocate(size, sizeof(project_interfaces__action__Patrol_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = project_interfaces__action__Patrol_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        project_interfaces__action__Patrol_FeedbackMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
project_interfaces__action__Patrol_FeedbackMessage__Sequence__fini(project_interfaces__action__Patrol_FeedbackMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      project_interfaces__action__Patrol_FeedbackMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

project_interfaces__action__Patrol_FeedbackMessage__Sequence *
project_interfaces__action__Patrol_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  project_interfaces__action__Patrol_FeedbackMessage__Sequence * array = (project_interfaces__action__Patrol_FeedbackMessage__Sequence *)allocator.allocate(sizeof(project_interfaces__action__Patrol_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = project_interfaces__action__Patrol_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
project_interfaces__action__Patrol_FeedbackMessage__Sequence__destroy(project_interfaces__action__Patrol_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    project_interfaces__action__Patrol_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
project_interfaces__action__Patrol_FeedbackMessage__Sequence__are_equal(const project_interfaces__action__Patrol_FeedbackMessage__Sequence * lhs, const project_interfaces__action__Patrol_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!project_interfaces__action__Patrol_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
project_interfaces__action__Patrol_FeedbackMessage__Sequence__copy(
  const project_interfaces__action__Patrol_FeedbackMessage__Sequence * input,
  project_interfaces__action__Patrol_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(project_interfaces__action__Patrol_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    project_interfaces__action__Patrol_FeedbackMessage * data =
      (project_interfaces__action__Patrol_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!project_interfaces__action__Patrol_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          project_interfaces__action__Patrol_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!project_interfaces__action__Patrol_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
