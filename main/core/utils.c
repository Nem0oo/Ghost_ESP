#include "core/utils.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <string.h>

bool is_in_task_context(void)
{
    if (xTaskGetCurrentTaskHandle() != NULL) {
        return true;
    } else {
        return false;
    }
}

void url_decode(char *decoded, const char *encoded) {
    char c;
    int i, j = 0;
    for (i = 0; encoded[i] != '\0'; i++) {
        if (encoded[i] == '%') {
            sscanf(&encoded[i + 1], "%2hhx", &c);
            decoded[j++] = c;
            i += 2;
        } else if (encoded[i] == '+') {
            decoded[j++] = ' ';
        } else {
            decoded[j++] = encoded[i];
        }
    }
    decoded[j] = '\0';
}

int get_query_param_value(const char *query, const char *key, char *value, size_t value_size) {
    char *param_start = strstr(query, key);
    if (param_start) {
        param_start += strlen(key) + 1;
        char *param_end = strchr(param_start, '&');
        if (param_end == NULL) {
            param_end = param_start + strlen(param_start); 
        }

        size_t param_len = param_end - param_start;
        if (param_len >= value_size) {
            return ESP_ERR_INVALID_SIZE;
        }
        strncpy(value, param_start, param_len);
        value[param_len] = '\0';
        return ESP_OK;
    }
    return ESP_ERR_NOT_FOUND;
}