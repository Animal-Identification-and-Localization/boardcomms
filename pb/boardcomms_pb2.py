import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf.internal import enum_type_wrapper
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='boardcomms.proto',
  package='',
  syntax='proto2',
  serialized_options=None,
  serialized_pb=_b('\n\x10\x62oardcomms.proto\"m\n\rCoralToATMega\x12!\n\x0cmessage_type\x18\x01 \x02(\x0e\x32\x0b.C2AMsgType\x12\n\n\x02\x64x\x18\x02 \x01(\x05\x12\n\n\x02\x64y\x18\x03 \x01(\x05\x12\x0f\n\x07pingnum\x18\x04 \x01(\x05\x12\x10\n\x08laser_on\x18\x05 \x01(\x08\"V\n\rATMegaToCoral\x12!\n\x0cmessage_type\x18\x01 \x02(\x0e\x32\x0b.C2AMsgType\x12\x0b\n\x03\x61\x63k\x18\x02 \x02(\x05\x12\x15\n\rping_response\x18\x03 \x01(\x05*+\n\nC2AMsgType\x12\x08\n\x04PING\x10\x00\x12\x08\n\x04\x44XDY\x10\x01\x12\t\n\x05LASER\x10\x02*!\n\nA2CMsgType\x12\n\n\x06PING_R\x10\x00\x12\x07\n\x03\x41\x43K\x10\x01')
)

_C2AMSGTYPE = _descriptor.EnumDescriptor(
  name='C2AMsgType',
  full_name='C2AMsgType',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='PING', index=0, number=0,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='DXDY', index=1, number=1,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='LASER', index=2, number=2,
      serialized_options=None,
      type=None),
  ],
  containing_type=None,
  serialized_options=None,
  serialized_start=219,
  serialized_end=262,
)
_sym_db.RegisterEnumDescriptor(_C2AMSGTYPE)

C2AMsgType = enum_type_wrapper.EnumTypeWrapper(_C2AMSGTYPE)
_A2CMSGTYPE = _descriptor.EnumDescriptor(
  name='A2CMsgType',
  full_name='A2CMsgType',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='PING_R', index=0, number=0,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='ACK', index=1, number=1,
      serialized_options=None,
      type=None),
  ],
  containing_type=None,
  serialized_options=None,
  serialized_start=264,
  serialized_end=297,
)
_sym_db.RegisterEnumDescriptor(_A2CMSGTYPE)

A2CMsgType = enum_type_wrapper.EnumTypeWrapper(_A2CMSGTYPE)
PING = 0
DXDY = 1
LASER = 2
PING_R = 0
ACK = 1



_CORALTOATMEGA = _descriptor.Descriptor(
  name='CoralToATMega',
  full_name='CoralToATMega',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='message_type', full_name='CoralToATMega.message_type', index=0,
      number=1, type=14, cpp_type=8, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='dx', full_name='CoralToATMega.dx', index=1,
      number=2, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='dy', full_name='CoralToATMega.dy', index=2,
      number=3, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='pingnum', full_name='CoralToATMega.pingnum', index=3,
      number=4, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='laser_on', full_name='CoralToATMega.laser_on', index=4,
      number=5, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=20,
  serialized_end=129,
)


_ATMEGATOCORAL = _descriptor.Descriptor(
  name='ATMegaToCoral',
  full_name='ATMegaToCoral',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='message_type', full_name='ATMegaToCoral.message_type', index=0,
      number=1, type=14, cpp_type=8, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='ack', full_name='ATMegaToCoral.ack', index=1,
      number=2, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='ping_response', full_name='ATMegaToCoral.ping_response', index=2,
      number=3, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=131,
  serialized_end=217,
)

_CORALTOATMEGA.fields_by_name['message_type'].enum_type = _C2AMSGTYPE
_ATMEGATOCORAL.fields_by_name['message_type'].enum_type = _C2AMSGTYPE
DESCRIPTOR.message_types_by_name['CoralToATMega'] = _CORALTOATMEGA
DESCRIPTOR.message_types_by_name['ATMegaToCoral'] = _ATMEGATOCORAL
DESCRIPTOR.enum_types_by_name['C2AMsgType'] = _C2AMSGTYPE
DESCRIPTOR.enum_types_by_name['A2CMsgType'] = _A2CMSGTYPE
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

CoralToATMega = _reflection.GeneratedProtocolMessageType('CoralToATMega', (_message.Message,), dict(
  DESCRIPTOR = _CORALTOATMEGA,
  __module__ = 'boardcomms_pb2'
  # @@protoc_insertion_point(class_scope:CoralToATMega)
  ))
_sym_db.RegisterMessage(CoralToATMega)

ATMegaToCoral = _reflection.GeneratedProtocolMessageType('ATMegaToCoral', (_message.Message,), dict(
  DESCRIPTOR = _ATMEGATOCORAL,
  __module__ = 'boardcomms_pb2'
  # @@protoc_insertion_point(class_scope:ATMegaToCoral)
  ))
_sym_db.RegisterMessage(ATMegaToCoral)


# @@protoc_insertion_point(module_scope)