/* **********************************************************
 * Copyright (c) 2017-2018 Google, Inc.  All rights reserved.
 * **********************************************************/

/*
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Google, Inc. nor the names of its contributors may be
 *   used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL VMWARE, INC. OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 */

#ifndef _RAW2TRACE_DIRECTORY_H_
#define _RAW2TRACE_DIRECTORY_H_ 1

#include <fstream>
#include <string>
#include <vector>

#include "dr_api.h"

class raw2trace_directory_t {
public:
    // If outdir.empty() then a peer of indir's OUTFILE_SUBDIR named TRACE_SUBDIR
    // is used by default.
    raw2trace_directory_t(const std::string &indir, const std::string &outdir,
                          unsigned int verbosity = 0);
    // This version is for constructing module_mapper_t.
    raw2trace_directory_t(const std::string &module_file_path,
                          unsigned int verbosity = 0);
    ~raw2trace_directory_t();

    static std::string
    tracedir_from_rawdir(const std::string &rawdir);

    char *modfile_bytes;
    std::vector<std::istream *> in_files;
    std::vector<std::ostream *> out_files;

private:
    void
    read_module_file(const std::string &modfilename);
    void
    open_thread_files();
    void
    open_thread_log_file(const char *basename);
    file_t modfile;
    std::string indir;
    std::string outdir;
    unsigned int verbosity;
};

#endif /* _RAW2TRACE_DIRECTORY_H_ */
