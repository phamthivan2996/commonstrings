#ifndef COMMON_MULTIPLE_STRINGS_H
#define COMMON_MULTIPLE_STRINGS_H
#include "auxiliary/suffix_tree_simple.h"
#include <iostream>
#include <vector>
#include <fstream>
class Common_multiple_strings
{
public:
	int number_strings;
	Suffix_tree_simple tree;
	Common_multiple_strings(){};
	void from_path(std::string &path);
	void from_strings(std::vector< std::string > strings);
	void build();
	std::vector< std::string > query(int k);
	int length_longest_substring(int i);
	std::vector< std::string > filter_substrings_by_length(int i, int length_input);
};

void Common_multiple_strings::from_path(std::string &path)
{
        std::ifstream input_file(path);
        std::string text_read;
        std::vector< std::string > strings;
        while (std::getline(input_file, text_read))
                strings.push_back(text_read);
        number_strings = strings.size();
        tree.from_string(strings);
        build();
}

void Common_multiple_strings::from_strings(std::vector< std::string > strings)
{
        number_strings = strings.size();
        tree.from_string(strings);
        build();
}

void Common_multiple_strings::build()
{
        tree.build();
        tree.init_array();
        tree.set_index_dfs(0, tree.input.size());
        tree.free_mem_dfs();
        tree.lca(0);
        tree.free_mem_lca();
        tree.cal_c(0);
}

std::vector< std::string > Common_multiple_strings::query(int k)
{
        return tree.query(k);
}

int Common_multiple_strings::length_longest_substring(int i)
{
        return tree.length_longest_substring(i);
}

std::vector< std::string > Common_multiple_strings::filter_substrings_by_length(int i, int length_input)
{
        return tree.filter_substrings_by_length(i, length_input);
}

#endif
