import os
import re


class Solution:
    def __init__(self):
        pass


def get_sol():
    sols = []
    dir_path = os.getcwd() + "\\ProblemSet\\"
    file_lists = os.listdir(dir_path)

    for f in file_lists:
        try:
            fp = open(dir_path + f, 'r')
            lines = fp.readlines()[:3]

            info = re.match(r'(//)(\s*)(\d{1,3})(\.)(\s*)([\w -]+)', lines[0])
            src = re.match(r'(.*)(https://leetcode.com/problems/.*)', lines[1])
            dif = re.match(r'(.*)(difficulty)([:\s]*)(\w+)', lines[2])

            sol = Solution()
            sol.file_path = "ProblemSet/" + f
            sol.num = info.groups()[2]
            sol.name = info.groups()[5]
            sol.url = src.groups()[1]
            sol.dif = dif.groups()[3]
            sols.append(sol)

            fp.close()

        except:
            print("Something goes wrong with ", f)

    return sorted(sols, key=lambda obj: int(obj.num))


def write_md(sols):
    fp = open('README.md', 'w')

    fp.write('# LeetCode\n\n' +
             '**My LeetCode solutions.** \n\n' +
             '|NO.|Title|Difficulty|Solution|\n' +
             '|---|-----|----------|--------|\n')

    for sol in sols:
        fp.write('|' + sol.num + '|[' + sol.name + '](' +
                 sol.url + ')|' + sol.dif + '|[C++](' +
                 sol.file_path + ')|\n')

    fp.close()
    print("README.md updated.")


def main():
    sols = get_sol()
    if sols:
        write_md(sols)


main()