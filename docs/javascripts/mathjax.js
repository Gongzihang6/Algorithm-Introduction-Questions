window.MathJax = {
    tex: {
        inlineMath: [["\\(", "\\)"]],
        displayMath: [["\\[", "\\]"]],
        processEscapes: true,
        processEnvironments: true
    },
    options: {
        ignoreHtmlClass: ".*|",
        processHtmlClass: "arithmatex"
    },
    // 新增：启动后监听 DOM 变化（针对某些动态加载场景）
    startup: {
        pageReady: () => {
            return MathJax.startup.defaultPageReady().then(() => {
                console.log("MathJax initial rendering done");
            });
        }
    }
};
