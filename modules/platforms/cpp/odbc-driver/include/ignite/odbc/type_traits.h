/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _IGNITE_ODBC_DRIVER_TYPE_TRAITS
#define _IGNITE_ODBC_DRIVER_TYPE_TRAITS

#include <stdint.h>

namespace ignite
{
    namespace odbc
    {
        namespace type_traits
        {
            /** 
             * ODBC type aliases.
             * We use these so we will not be needed to include system-specific
             * headers in our header files.
             */
            enum IgniteSqlType
            {
                /** Alias for the SQL_C_CHAR type. */
                IGNITE_ODBC_C_TYPE_CHAR,

                /** Alias for the SQL_C_WCHAR type. */
                IGNITE_ODBC_C_TYPE_WCHAR,

                /** Alias for the SQL_C_SSHORT type. */
                IGNITE_ODBC_C_TYPE_SIGNED_SHORT,

                /** Alias for the SQL_C_USHORT type. */
                IGNITE_ODBC_C_TYPE_UNSIGNED_SHORT,

                /** Alias for the SQL_C_WCHAR type. */
                IGNITE_ODBC_C_TYPE_SIGNED_LONG,

                /** Alias for the SQL_C_WCHAR type. */
                IGNITE_ODBC_C_TYPE_UNSIGNED_LONG,

                /** Alias for the SQL_C_WCHAR type. */
                IGNITE_ODBC_C_TYPE_FLOAT,

                /** Alias for the SQL_C_WCHAR type. */
                IGNITE_ODBC_C_TYPE_DOUBLE,

                /** Alias for the SQL_C_WCHAR type. */
                IGNITE_ODBC_C_TYPE_BIT,

                /** Alias for the SQL_C_WCHAR type. */
                IGNITE_ODBC_C_TYPE_SIGNED_TINYINT,

                /** Alias for the SQL_C_WCHAR type. */
                IGNITE_ODBC_C_TYPE_UNSIGNED_TINYINT,

                /** Alias for the SQL_C_WCHAR type. */
                IGNITE_ODBC_C_TYPE_SIGNED_BIGINT,

                /** Alias for the SQL_C_WCHAR type. */
                IGNITE_ODBC_C_TYPE_UNSIGNED_BIGINT,

                /** Alias for the SQL_C_WCHAR type. */
                IGNITE_ODBC_C_TYPE_BINARY,

                /** Alias for the SQL_C_WCHAR type. */
                IGNITE_ODBC_C_TYPE_TDATE,

                /** Alias for the SQL_C_WCHAR type. */
                IGNITE_ODBC_C_TYPE_TTIME,

                /** Alias for the SQL_C_WCHAR type. */
                IGNITE_ODBC_C_TYPE_TTIMESTAMP,

                /** Alias for the SQL_C_WCHAR type. */
                IGNITE_ODBC_C_TYPE_NUMERIC,

                /** Alias for the SQL_C_WCHAR type. */
                IGNITE_ODBC_C_TYPE_GUID,

                /** Alias for the SQL_DEFAULT. */
                IGNITE_ODBC_C_TYPE_DEFAULT,

                /** Alias for all unsupported types. */
                IGNITE_ODBC_C_TYPE_UNSUPPORTED
            };

            /**
             * Check if the C type supported by the current implementation.
             *
             * @param type Application type.
             * @return True if the type is supported.
             */
            bool IsApplicationTypeSupported(int16_t type);

            /**
             * Check if the SQL type supported by the current implementation.
             *
             * @param type Application type.
             * @return True if the type is supported.
             */
            bool IsSqlTypeSupported(int16_t type);

            /**
             * Convert ODBC type to driver type alias.
             *
             * @param ODBC type;
             * @return Internal driver type.
             */
            IgniteSqlType ToDriverType(int16_t type);

            /**
             * Convert binary data type to SQL data type.
             *
             * @param binaryType Binary data type.
             * @return SQL data type.
             */
            int16_t BinaryToSqlType(int8_t binaryType);

            /**
             * Get binary type SQL nullability.
             *
             * @param binaryType Binary data type.
             * @return SQL_NO_NULLS if the column could not include NULL values.
             *         SQL_NULLABLE if the column accepts NULL values.
             *         SQL_NULLABLE_UNKNOWN if it is not known whether the 
             *         column accepts NULL values.
             */
            int16_t BinaryTypeNullability(int8_t binaryType);
        }
    }
}

#endif