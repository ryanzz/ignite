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

#ifndef _IGNITE_IMPL_PORTABLE_SCHEMA
#define _IGNITE_IMPL_PORTABLE_SCHEMA

#include <vector>
#include <stdint.h>

#include <ignite/common/common.h>
#include <ignite/impl/interop/interop_output_stream.h>

namespace ignite
{
    namespace impl
    {
        namespace portable
        {
            /** Portable writer implementation forward declaration. */
            class PortableWriterImpl;

            /**
             * Portable schema.
             */
            class IGNITE_IMPORT_EXPORT PortableSchema
            {
            public:
                /**
                 * Default constructor.
                 */
                PortableSchema();

                /**
                 * Destructor.
                 */
                ~PortableSchema();

                /**
                 * Add another field to schema.
                 *
                 * @param id Field id.
                 * @param offset Field offset.
                 */
                void AddField(int32_t fieldId, int32_t offset);

                /**
                 * Write Schema to stream.
                 *
                 * @param out Stream to write schema to.
                 */
                void Write(interop::InteropOutputStream& out) const;

                /**
                 * Get Schema ID.
                 *
                 * @return Schema id.
                 */
                int32_t GetId() const
                {
                    return id;
                }

                /** 
                 * Check if the schema contains field info.
                 *
                 * @return True if does not contain field info.
                 */
                bool Empty() const;

                /** 
                 * Clear schema info.
                 */
                void Clear();

            private:
                /**
                * Single schema field info.
                */
                struct PortableSchemaFieldInfo
                {
                    int32_t id;
                    int32_t offset;
                };

                /** Type alias for vector of field info. */
                typedef std::vector<PortableSchemaFieldInfo> FieldContainer;

                /** Schema ID. */
                int32_t id;

                /** Information about written fields. */
                FieldContainer* fieldsInfo;

                IGNITE_NO_COPY_ASSIGNMENT(PortableSchema)
            };
        }
    }
}

#endif