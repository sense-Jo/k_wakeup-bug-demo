#include <zephyr/kernel.h>

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(main);

/* Thread */
K_THREAD_STACK_DEFINE(threadStack, 2048);
struct k_thread thread;
k_tid_t threadId;

static void threadFkn() {
	LOG_INF("test-thread started!");
}

int main() {
  threadId =
      k_thread_create(&thread, threadStack, K_THREAD_STACK_SIZEOF(threadStack),
                      threadFkn, NULL, NULL, NULL, 5, 0, K_SECONDS(2));
  k_thread_name_set(threadId, "test_thread");

  k_sleep(K_SECONDS(1));
  k_wakeup(threadId);
	LOG_INF("woke up test-thread");
  
  k_sleep(K_SECONDS(1));
  k_thread_resume(threadId);
	LOG_INF("resumed test-thread");
  
  while (true) {
    k_sleep(K_SECONDS(1));
  }
  return 0;
}
