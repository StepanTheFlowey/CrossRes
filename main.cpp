#include "main.hpp"

#if _WIN32

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <stdexcept>

extern const char* resourceType;

ResourceSize loadResourceSize(const uint32_t id) {
  ResourceSize resource;

  HRSRC hResource = FindResourceA(NULL, MAKEINTRESOURCEA(id + 200), resourceType);
  if(!hResource) {
    throw std::runtime_error("Failed to find Win32 resource");
  }

  HGLOBAL hMemory = LoadResource(NULL, hResource);
  if(!hMemory) {
    throw std::runtime_error("Failed to load Win32 resource");
  }

  resource.data = LockResource(hMemory);
  resource.size = SizeofResource(NULL, hResource);

  return resource;
}

ResourcePtrs loadResourcePtrs(const uint32_t id) {
  ResourcePtrs resource;

  HRSRC hResource = FindResourceA(NULL, MAKEINTRESOURCEA(id + 200), resourceType);
  if(!hResource) {
    throw std::runtime_error("Failed to find Win32 resource");
  }

  HGLOBAL hMemory = LoadResource(NULL, hResource);
  if(!hMemory) {
    throw std::runtime_error("Failed to load Win32 resource");
  }

  resource.begin = LockResource(hMemory);
  resource.end = reinterpret_cast<char*>(resource.begin) + SizeofResource(NULL, hResource);

  return resource;
}

#elif __linux__

extern const ResourcePtrs resources[];

ResourceSize loadResourceSize(const uint32_t id) {
  ResourceSize resource;

  resource.data = resources[id].begin;
  resource.size = reinterpret_cast<uintptr_t>(resources[id].end) - reinterpret_cast<uintptr_t>(resources[id].begin);

  return resource;
}

ResourcePtrs loadResourcePtrs(const uint32_t id) {
  ResourcePtrs resource = resources[id];

  return resource;
}

#endif
