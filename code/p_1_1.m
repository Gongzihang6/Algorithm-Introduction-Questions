% 定义函数
function y = myFunc(n)
    y = factorial(n);
end


% 给定 t
t = 1000;

% 使用 fzero 找到 f(n) = t 的解
n0 = fzero(@(n) myFunc(n) - t, 10);

% 检查解的整数部分
n_max = floor(n0);

% 验证 n_max 是否满足不等式
if (myFunc(n_max) <= t) && (myFunc(n_max+1) > t)
    disp(['满足不等式的最大 n 为: ', num2str(n_max)]);
end