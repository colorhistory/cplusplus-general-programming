﻿#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP

#include "bits/stdc++.h"

namespace GP {
    namespace experimental {
        namespace filesystem {
            inline namespace v1 {
                class path;

                void swap(path& lhs, path& rhs) noexcept;
                size_t hash_value(const path& p) noexcept;

                bool operator==(const path& lhs, const path& rhs) noexcept;
                bool operator!=(const path& lhs, const path& rhs) noexcept;
                bool operator<(const path& lhs, const path& rhs) noexcept;
                bool operator<=(const path& lhs, const path& rhs) noexcept;
                bool operator>(const path& lhs, const path& rhs) noexcept;
                bool operator>=(const path& lhs, const path& rhs) noexcept;

                path operator/(const path& lhs, const path& rhs);

                // fs.path.io operators are friends of path.
                template <class charT, class traits>
                friend std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os,
                                                                     const path& p);

                template <class charT, class traits>
                friend std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& is, path& p);

                template <class Source>
                path u8path(const Source& source);
                template <class InputIterator>
                path u8path(InputIterator first, InputIterator last);

                class filesystem_error;
                class directory_entry;

                class directory_iterator;

                // enable directory_iterator range-based for statements
                directory_iterator begin(directory_iterator iter) noexcept;
                directory_iterator end(const directory_iterator&) noexcept;

                class recursive_directory_iterator;

                // enable recursive_directory_iterator range-based for statements
                recursive_directory_iterator begin(recursive_directory_iterator iter) noexcept;
                recursive_directory_iterator end(const recursive_directory_iterator&) noexcept;

                class file_status;

                struct space_info {
                    uintmax_t capacity;
                    uintmax_t free;
                    uintmax_t available;
                };

                enum class file_type;
                enum class perms;
                enum class perm_options;
                enum class copy_options;
                enum class directory_options;

                typedef std::chrono::time_point<trivial - clock> file_time_type;

                // operational functions

                path absolute(const path& p);
                path absolute(const path& p, std::error_code& ec);

                path canonical(const path& p);
                path canonical(const path& p, std::error_code& ec);

                void copy(const path& from, const path& to);
                void copy(const path& from, const path& to, std::error_code& ec);
                void copy(const path& from, const path& to, copy_options options);
                void copy(const path& from, const path& to, copy_options options, std::error_code& ec);

                bool copy_file(const path& from, const path& to);
                bool copy_file(const path& from, const path& to, std::error_code& ec);
                bool copy_file(const path& from, const path& to, copy_options option);
                bool copy_file(const path& from, const path& to, copy_options option, std::error_code& ec);

                void copy_symlink(const path& existing_symlink, const path& new_symlink);
                void copy_symlink(const path& existing_symlink, const path& new_symlink, std::error_code& ec) noexcept;

                bool create_directories(const path& p);
                bool create_directories(const path& p, std::error_code& ec);

                bool create_directory(const path& p);
                bool create_directory(const path& p, error_code& ec) noexcept;

                bool create_directory(const path& p, const path& attributes);
                bool create_directory(const path& p, const path& attributes, std::error_code& ec) noexcept;

                void create_directory_symlink(const path& to, const path& new_symlink);
                void create_directory_symlink(const path& to, const path& new_symlink, std::error_code& ec) noexcept;

                void create_hard_link(const path& to, const path& new_hard_link);
                void create_hard_link(const path& to, const path& new_hard_link, std::error_code& ec) noexcept;

                void create_symlink(const path& to, const path& new_symlink);
                void create_symlink(const path& to, const path& new_symlink, std::error_code& ec) noexcept;

                path current_path();
                path current_path(std::error_code& ec);
                void current_path(const path& p);
                void current_path(const path& p, std::error_code& ec) noexcept;

                bool exists(file_status s) noexcept;
                bool exists(const path& p);
                bool exists(const path& p, std::error_code& ec) noexcept;

                bool equivalent(const path& p1, const path& p2);
                bool equivalent(const path& p1, const path& p2, std::error_code& ec) noexcept;

                uintmax_t file_size(const path& p);
                uintmax_t file_size(const path& p, std::error_code& ec) noexcept;

                uintmax_t hard_link_count(const path& p);
                uintmax_t hard_link_count(const path& p, std::error_code& ec) noexcept;

                bool is_block_file(file_status s) noexcept;
                bool is_block_file(const path& p);
                bool is_block_file(const path& p, std::error_code& ec) noexcept;

                bool is_character_file(file_status s) noexcept;
                bool is_character_file(const path& p);
                bool is_character_file(const path& p, std::error_code& ec) noexcept;

                bool is_directory(file_status s) noexcept;
                bool is_directory(const path& p);
                bool is_directory(const path& p, std::error_code& ec) noexcept;

                bool is_empty(const path& p);
                bool is_empty(const path& p, std::error_code& ec) noexcept;

                bool is_fifo(file_status s) noexcept;
                bool is_fifo(const path& p);
                bool is_fifo(const path& p, std::error_code& ec) noexcept;

                bool is_other(file_status s) noexcept;
                bool is_other(const path& p);
                bool is_other(const path& p, std::error_code& ec) noexcept;

                bool is_regular_file(file_status s) noexcept;
                bool is_regular_file(const path& p);
                bool is_regular_file(const path& p, std::error_code& ec) noexcept;

                bool is_socket(file_status s) noexcept;
                bool is_socket(const path& p);
                bool is_socket(const path& p, std::error_code& ec) noexcept;

                bool is_symlink(file_status s) noexcept;
                bool is_symlink(const path& p);
                bool is_symlink(const path& p, std::error_code& ec) noexcept;

                file_time_type last_write_time(const path& p);
                file_time_type last_write_time(const path& p, std::error_code& ec) noexcept;
                void last_write_time(const path& p, file_time_type new_time);
                void last_write_time(const path& p, file_time_type new_time, std::error_code& ec) noexcept;

                void permissions(const path& p, perms prms, perm_options opts = perm_options::replace);
                void permissions(const path& p, perms prms, std::error_code& ec) noexcept;
                void permissions(const path& p, perms prms, perm_options opts, std::error_code& ec);

                path proximate(const path& p, std::error_code& ec);
                path proximate(const path& p, const path& base = current_path());
                path proximate(const path& p, const path& base, std::error_code& ec);

                path read_symlink(const path& p);
                path read_symlink(const path& p, std::error_code& ec);

                path relative(const path& p, std::error_code& ec);
                path relative(const path& p, const path& base = current_path());
                path relative(const path& p, const path& base, std::error_code& ec);

                bool remove(const path& p);
                bool remove(const path& p, std::error_code& ec) noexcept;

                uintmax_t remove_all(const path& p);
                uintmax_t remove_all(const path& p, std::error_code& ec);

                void rename(const path& from, const path& to);
                void rename(const path& from, const path& to, std::error_code& ec) noexcept;

                void resize_file(const path& p, uintmax_t size);
                void resize_file(const path& p, uintmax_t size, std::error_code& ec) noexcept;

                space_info space(const path& p);
                space_info space(const path& p, std::error_code& ec) noexcept;

                file_status status(const path& p);
                file_status status(const path& p, std::error_code& ec) noexcept;

                bool status_known(file_status s) noexcept;

                file_status symlink_status(const path& p);
                file_status symlink_status(const path& p, std::error_code& ec) noexcept;

                path temp_directory_path();
                path temp_directory_path(std::error_code& ec);

                path weakly_canonical(path const& p);
                path weakly_canonical(path const& p, std::error_code& ec);

            }  // namespace v1
        }      // namespace filesystem
    }          // namespace experimental
}  // namespace GP

#endif  // FILESYSTEM_HPP
