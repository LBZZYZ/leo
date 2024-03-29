// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: IM.Login.proto

#include "IM.Login.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace IM {
namespace Login {
class UserLoginRqDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<UserLoginRq> _instance;
} _UserLoginRq_default_instance_;
}  // namespace Login
}  // namespace IM
static void InitDefaultsscc_info_UserLoginRq_IM_2eLogin_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::IM::Login::_UserLoginRq_default_instance_;
    new (ptr) ::IM::Login::UserLoginRq();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_UserLoginRq_IM_2eLogin_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_UserLoginRq_IM_2eLogin_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_IM_2eLogin_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_IM_2eLogin_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_IM_2eLogin_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_IM_2eLogin_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::IM::Login::UserLoginRq, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::IM::Login::UserLoginRq, id_),
  PROTOBUF_FIELD_OFFSET(::IM::Login::UserLoginRq, password_),
  PROTOBUF_FIELD_OFFSET(::IM::Login::UserLoginRq, user_status_),
  PROTOBUF_FIELD_OFFSET(::IM::Login::UserLoginRq, client_type_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::IM::Login::UserLoginRq)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::IM::Login::_UserLoginRq_default_instance_),
};

const char descriptor_table_protodef_IM_2eLogin_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\016IM.Login.proto\022\010IM.Login\032\rIM.Base.prot"
  "o\"\177\n\013UserLoginRq\022\n\n\002id\030\001 \001(\t\022\020\n\010password"
  "\030\002 \001(\t\022(\n\013user_status\030\003 \001(\0162\023.IM.Base.Us"
  "erStatus\022(\n\013client_type\030\004 \001(\0162\023.IM.Base."
  "ClientTypeb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_IM_2eLogin_2eproto_deps[1] = {
  &::descriptor_table_IM_2eBase_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_IM_2eLogin_2eproto_sccs[1] = {
  &scc_info_UserLoginRq_IM_2eLogin_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_IM_2eLogin_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_IM_2eLogin_2eproto = {
  false, false, descriptor_table_protodef_IM_2eLogin_2eproto, "IM.Login.proto", 178,
  &descriptor_table_IM_2eLogin_2eproto_once, descriptor_table_IM_2eLogin_2eproto_sccs, descriptor_table_IM_2eLogin_2eproto_deps, 1, 1,
  schemas, file_default_instances, TableStruct_IM_2eLogin_2eproto::offsets,
  file_level_metadata_IM_2eLogin_2eproto, 1, file_level_enum_descriptors_IM_2eLogin_2eproto, file_level_service_descriptors_IM_2eLogin_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_IM_2eLogin_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_IM_2eLogin_2eproto)), true);
namespace IM {
namespace Login {

// ===================================================================

class UserLoginRq::_Internal {
 public:
};

UserLoginRq::UserLoginRq(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:IM.Login.UserLoginRq)
}
UserLoginRq::UserLoginRq(const UserLoginRq& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_id().empty()) {
    id_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_id(), 
      GetArena());
  }
  password_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_password().empty()) {
    password_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_password(), 
      GetArena());
  }
  ::memcpy(&user_status_, &from.user_status_,
    static_cast<size_t>(reinterpret_cast<char*>(&client_type_) -
    reinterpret_cast<char*>(&user_status_)) + sizeof(client_type_));
  // @@protoc_insertion_point(copy_constructor:IM.Login.UserLoginRq)
}

void UserLoginRq::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_UserLoginRq_IM_2eLogin_2eproto.base);
  id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  password_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
      reinterpret_cast<char*>(&user_status_) - reinterpret_cast<char*>(this)),
      0, static_cast<size_t>(reinterpret_cast<char*>(&client_type_) -
      reinterpret_cast<char*>(&user_status_)) + sizeof(client_type_));
}

UserLoginRq::~UserLoginRq() {
  // @@protoc_insertion_point(destructor:IM.Login.UserLoginRq)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void UserLoginRq::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  id_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  password_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void UserLoginRq::ArenaDtor(void* object) {
  UserLoginRq* _this = reinterpret_cast< UserLoginRq* >(object);
  (void)_this;
}
void UserLoginRq::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void UserLoginRq::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const UserLoginRq& UserLoginRq::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_UserLoginRq_IM_2eLogin_2eproto.base);
  return *internal_default_instance();
}


void UserLoginRq::Clear() {
// @@protoc_insertion_point(message_clear_start:IM.Login.UserLoginRq)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  id_.ClearToEmpty();
  password_.ClearToEmpty();
  ::memset(&user_status_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&client_type_) -
      reinterpret_cast<char*>(&user_status_)) + sizeof(client_type_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* UserLoginRq::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_id();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "IM.Login.UserLoginRq.id"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string password = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_password();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "IM.Login.UserLoginRq.password"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .IM.Base.UserStatus user_status = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_user_status(static_cast<::IM::Base::UserStatus>(val));
        } else goto handle_unusual;
        continue;
      // .IM.Base.ClientType client_type = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_client_type(static_cast<::IM::Base::ClientType>(val));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* UserLoginRq::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:IM.Login.UserLoginRq)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string id = 1;
  if (this->id().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_id().data(), static_cast<int>(this->_internal_id().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "IM.Login.UserLoginRq.id");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_id(), target);
  }

  // string password = 2;
  if (this->password().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_password().data(), static_cast<int>(this->_internal_password().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "IM.Login.UserLoginRq.password");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_password(), target);
  }

  // .IM.Base.UserStatus user_status = 3;
  if (this->user_status() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      3, this->_internal_user_status(), target);
  }

  // .IM.Base.ClientType client_type = 4;
  if (this->client_type() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      4, this->_internal_client_type(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:IM.Login.UserLoginRq)
  return target;
}

size_t UserLoginRq::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:IM.Login.UserLoginRq)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string id = 1;
  if (this->id().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_id());
  }

  // string password = 2;
  if (this->password().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_password());
  }

  // .IM.Base.UserStatus user_status = 3;
  if (this->user_status() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_user_status());
  }

  // .IM.Base.ClientType client_type = 4;
  if (this->client_type() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_client_type());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void UserLoginRq::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:IM.Login.UserLoginRq)
  GOOGLE_DCHECK_NE(&from, this);
  const UserLoginRq* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<UserLoginRq>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:IM.Login.UserLoginRq)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:IM.Login.UserLoginRq)
    MergeFrom(*source);
  }
}

void UserLoginRq::MergeFrom(const UserLoginRq& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:IM.Login.UserLoginRq)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.id().size() > 0) {
    _internal_set_id(from._internal_id());
  }
  if (from.password().size() > 0) {
    _internal_set_password(from._internal_password());
  }
  if (from.user_status() != 0) {
    _internal_set_user_status(from._internal_user_status());
  }
  if (from.client_type() != 0) {
    _internal_set_client_type(from._internal_client_type());
  }
}

void UserLoginRq::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:IM.Login.UserLoginRq)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void UserLoginRq::CopyFrom(const UserLoginRq& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:IM.Login.UserLoginRq)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UserLoginRq::IsInitialized() const {
  return true;
}

void UserLoginRq::InternalSwap(UserLoginRq* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  id_.Swap(&other->id_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  password_.Swap(&other->password_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(UserLoginRq, client_type_)
      + sizeof(UserLoginRq::client_type_)
      - PROTOBUF_FIELD_OFFSET(UserLoginRq, user_status_)>(
          reinterpret_cast<char*>(&user_status_),
          reinterpret_cast<char*>(&other->user_status_));
}

::PROTOBUF_NAMESPACE_ID::Metadata UserLoginRq::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace Login
}  // namespace IM
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::IM::Login::UserLoginRq* Arena::CreateMaybeMessage< ::IM::Login::UserLoginRq >(Arena* arena) {
  return Arena::CreateMessageInternal< ::IM::Login::UserLoginRq >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
