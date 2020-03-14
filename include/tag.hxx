#pragma once

#define CONCATENATE_HELPER(x, y) x##y
#define CONCATENATE(x, y) CONCATENATE_HELPER(x, y)
#define AUTO_TAG struct CONCATENATE(UniqueTag_, __COUNTER__)
#define TAG(tag_name) struct CONCATENATE(UniqueTag_, tag_name)
