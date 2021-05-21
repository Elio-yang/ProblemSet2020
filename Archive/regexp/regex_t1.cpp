/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/3/10
 */


#include<regex>
#include<string>
#include<iostream>

/*
若要判断一个输入的QQ号是否有效
对应规则:
1.长度大于5，小于等于11；
2.首位不能为0；
3.是否为纯数字？
*/
bool judge_qq_num(std::string qq_num) {
        std::regex qq_reg("[1-9]\\d{4,11}");
        bool ret = std::regex_match(qq_num, qq_reg);
        return ret;
}

bool match_html_label(std::string label) {
        std::regex lab_reg("(<.*>)(.*)(</.*>)");
        std::cmatch m;
        const char *str = label.c_str();
        auto ret = std::regex_match(str, m, lab_reg);
        if (ret) {
                std::cout << m.str() << std::endl;
                std::cout << m.length() << std::endl;
                std::cout << m.position() << std::endl;
                for (auto it = m.begin(); it != m.end(); ++it) {
                        //print group
                        std::cout << *it << std::endl;
                }

        }
        return ret;
}
bool search_html_label(std::string label) {
        std::regex lab_reg("(<.*>)(.*)(</.*>)");
        /*针对C字符串用cmatch*/
        std::cmatch m;
        const char *str = label.c_str();
        auto ret = std::regex_search(str, m, lab_reg);
        if (ret) {
                std::cout << m.str() << std::endl;
                std::cout << m.length() << std::endl;
                std::cout << m.position() << std::endl;
                for (auto it = m.begin(); it != m.end(); ++it) {
                        //print group
                        std::cout << *it << std::endl;
                }
                std::cout << "prefix:" << m.prefix() << std::endl;
                std::cout << "suffix:" << m.suffix() << std::endl;
        }
        return ret;
}

void still_search_html_label(std::string label) {
        //std::regex bug_reg("(<.*>)(.*)(<.*>)");
        std::regex lab_reg("<(.*)>(.*)<(/\\1)>");
        /*针对string 用smatch*/
        std::smatch m;
        auto pos = label.cbegin();
        auto end = label.cend();
        for (; std::regex_search(pos, end, m, lab_reg); pos = m.suffix().first) {
                std::cout << "------------------" << std::endl;
                std::cout << m.str() << std::endl;
                std::cout << "Group1:" << m [1].str() << std::endl;
                std::cout << "Group2:" << m [2].str() << std::endl;
                std::cout << "Group3:" << m [3].str() << std::endl;
        }

}

int main() {

        return 0;
}