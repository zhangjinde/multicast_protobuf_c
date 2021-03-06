/* Generated by the protocol buffer compiler.  DO NOT EDIT! */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C_NO_DEPRECATED
#define PROTOBUF_C_NO_DEPRECATED
#endif

#include "proto_multicast.pb-c.h"
void   multicast_msg__init
                     (MulticastMsg         *message)
{
  static MulticastMsg init_value = MULTICAST_MSG__INIT;
  *message = init_value;
}
size_t multicast_msg__get_packed_size
                     (const MulticastMsg *message)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &multicast_msg__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t multicast_msg__pack
                     (const MulticastMsg *message,
                      uint8_t       *out)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &multicast_msg__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t multicast_msg__pack_to_buffer
                     (const MulticastMsg *message,
                      ProtobufCBuffer *buffer)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &multicast_msg__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
MulticastMsg *
       multicast_msg__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (MulticastMsg *)
     protobuf_c_message_unpack (&multicast_msg__descriptor,
                                allocator, len, data);
}
void   multicast_msg__free_unpacked
                     (MulticastMsg *message,
                      ProtobufCAllocator *allocator)
{
  PROTOBUF_C_ASSERT (message->base.descriptor == &multicast_msg__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor multicast_msg__field_descriptors[1] =
{
  {
    "c",
    1,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_UINT64,
    PROTOBUF_C_OFFSETOF(MulticastMsg, n_c),
    PROTOBUF_C_OFFSETOF(MulticastMsg, c),
    NULL,
    NULL,
    0,            /* packed */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned multicast_msg__field_indices_by_name[] = {
  0,   /* field[0] = c */
};
static const ProtobufCIntRange multicast_msg__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor multicast_msg__descriptor =
{
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  "MulticastMsg",
  "MulticastMsg",
  "MulticastMsg",
  "",
  sizeof(MulticastMsg),
  1,
  multicast_msg__field_descriptors,
  multicast_msg__field_indices_by_name,
  1,  multicast_msg__number_ranges,
  (ProtobufCMessageInit) multicast_msg__init,
  NULL,NULL,NULL    /* reserved[123] */
};
