#ifndef _NGX_EVENT_PROBE_H_INCLUDED_
#define _NGX_EVENT_PROBE_H_INCLUDED_


#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_event.h>


#if (NGX_DTRACE)

#if (NGX_THREADS)
#   ifndef NGX_DEFINE_THREAD_POOL_T
#   define NGX_DEFINE_THREAD_POOL_T 1
typedef struct ngx_thread_pool_s  ngx_thread_pool_t;
#   endif
#endif

#include <ngx_http.h>
#include <ngx_dtrace_provider.h>

#define ngx_event_probe_timer_add(ev, timer)                                 \
    NGINX_TIMER_ADD(ev, timer)

#define ngx_event_probe_timer_del(ev)                                        \
    NGINX_TIMER_DEL(ev)

#define ngx_event_probe_timer_expire(ev)                                     \
    NGINX_TIMER_EXPIRE(ev)

#else /* !(NGX_DTRACE) */

#define ngx_event_probe_timer_add(ev, timer)
#define ngx_event_probe_timer_del(ev)
#define ngx_event_probe_timer_expire(ev)

#endif


#endif /* _NGX_EVENT_PROBE_H_INCLUDED_ */
