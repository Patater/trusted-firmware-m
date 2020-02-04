/*
 * Copyright (c) 2017-2020, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __OS_WRAPPER_THREAD_H__
#define __OS_WRAPPER_THREAD_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

/* prototype for the thread entry function */
typedef void (*os_wrapper_thread_func) (void *argument);

/**
 * \brief Creates a new thread
 *
 * \param[in] name        Name of the thread
 * \param[in] stack_size  Size of stack to be allocated for this thread. It can
 *                        be \ref OS_WRAPPER_DEFAULT_STACK_SIZE to use the
 *                        default value provided by the underlying RTOS
 * \param[in] func        Pointer to the function invoked by thread
 * \param[in] arg         Argument to pass to the function invoked by thread
 * \param[in] priority    Initial thread priority
 *
 * \return Returns the thread handle created, or NULL in case of error
 */
void *os_wrapper_thread_new(const char *name, int32_t stack_size,
                            os_wrapper_thread_func func, void *arg,
                            uint32_t priority);

/**
 * \brief Gets thread priority
 *
 * \param[in]  handle   Thread handle
 * \param[out] priority The priority of the thread
 *
 * \return Returns \ref OS_WRAPPER_SUCCESS on success, or \ref OS_WRAPPER_ERROR
 *                 in case of error
 */
uint32_t os_wrapper_thread_get_priority(void *handle, uint32_t *priority);

/**
 * \brief Gets the current thread priority
 *
 * \param[out] priority   The priority of the thread
 *
 * \return Returns \ref OS_WRAPPER_SUCCESS on success, or \ref OS_WRAPPER_ERROR
 *                 in case of error
 */
uint32_t os_wrapper_current_thread_get_priority(uint32_t *priority);

/**
 * \brief Terminate the thread and free any resources used by it
 *
 * \param[in]  handle   Thread handle
 *
 * \return Returns \ref OS_WRAPPER_SUCCESS on success, or \ref OS_WRAPPER_ERROR
 *                 in case of error
 */
uint32_t os_wrapper_thread_terminate(void *handle);

/**
 * \brief Suspend the current thread
 *        If you are suspending with the intention of terminating the thread,
 *        note that this function may not free all resources associated with
 *        the thread. Ensure that os_wrapper_thread_terminate() is also called
 *        to free all thread resources.
 *
 * \return Returns \ref OS_WRAPPER_SUCCESS on success, or \ref OS_WRAPPER_ERROR
 *                 in case of error
 */
uint32_t os_wrapper_current_thread_suspend(void);

#ifdef __cplusplus
}
#endif

#endif /* __OS_WRAPPER_THREAD_H__ */
