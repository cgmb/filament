/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef TNT_FILAFLAT_BLOBDICTIONARY_H
#define TNT_FILAFLAT_BLOBDICTIONARY_H

#include <vector>

#include <stddef.h>

namespace filaflat {

// Flat list of blobs that can be referenced by index.
class BlobDictionary {
public:
    BlobDictionary() = default;
    ~BlobDictionary() = default;

    inline void addBlob(const char* blob, size_t len) noexcept {
        mBlobs.push_back({ blob, len });
    }

    inline bool isEmpty() const noexcept {
        return mBlobs.empty();
    }

    inline void reserve(size_t size) {
        mBlobs.reserve(size);
    }

    inline const char* getBlob(size_t index, size_t* size) const noexcept {
        *size = mBlobs[index].size;
        return mBlobs[index].data;
    }

    inline const char* getString(size_t index) const noexcept {
        size_t size;
        return getBlob(index, &size);
    }


private:
    struct Blob {
        const char* data;
        size_t size;
    };
    std::vector<Blob> mBlobs;
};

} // namespace filaflat

#endif // TNT_FILAFLAT_BLOBDICTIONARY_H
