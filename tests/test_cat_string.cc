/*
  +--------------------------------------------------------------------------+
  | libcat                                                                   |
  +--------------------------------------------------------------------------+
  | Licensed under the Apache License, Version 2.0 (the "License");          |
  | you may not use this file except in compliance with the License.         |
  | You may obtain a copy of the License at                                  |
  | http://www.apache.org/licenses/LICENSE-2.0                               |
  | Unless required by applicable law or agreed to in writing, software      |
  | distributed under the License is distributed on an "AS IS" BASIS,        |
  | WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. |
  | See the License for the specific language governing permissions and      |
  | limitations under the License. See accompanying LICENSE file.            |
  +--------------------------------------------------------------------------+
  | Author: codinghuang <2812240764@qq.com>                                  |
  +--------------------------------------------------------------------------+
 */

#include "test.h"

#define CAT_TEST_DEFAULT_STRING_LENGTH    16

TEST(cat_string, hexprint)
{
    char in[] = "hello";
    char *out;

    out = cat_hexprint(in, CAT_STRLEN(in));
    ASSERT_NE(nullptr, out);
    ASSERT_STREQ("0x68 0x65 0x6C 0x6C 0x6F", out);
    cat_free(out);
}

TEST(cat_string, srand_zero_termination)
{
    char buffer[8];

    ASSERT_EQ(buffer, cat_srand(CAT_STRS(buffer)));
    ASSERT_EQ(CAT_STRLEN(buffer), strlen(buffer));
}

TEST(cat_string, srand_not_null_buffer)
{
    char buffer[8];

    ASSERT_EQ(buffer, cat_srand(CAT_STRS(buffer)));
}

TEST(cat_string, srand_null_buffer)
{
    char *out;

    out = cat_srand(nullptr, 8);
    ASSERT_NE(nullptr, out);
    cat_free(out);
}

TEST(cat_string, snrand_not_null_buffer)
{
    char buffer[8];

    ASSERT_EQ(buffer, cat_snrand(CAT_STRS(buffer)));
}

TEST(cat_string, snrand_null_buffer)
{
    char *out;

    out = cat_snrand(nullptr, 8);
    ASSERT_NE(nullptr, out);
    cat_free(out);
}
