#include "main.h"

/**
 * bltn_cd - changing directory
 * @d: data struct input
 * Return: void
 */
void bltn_cd(data *d)
{
        char *dir = d->av[1];
        char cwd[256];

        if (getcwd(cwd, sizeof(cwd)) == NULL)
                perror("getcwd() error");
        _setenv(d, "PWD", cwd);
        if (!dir)
                dir = _getenv("HOME");
        if (chdir(dir) == -1)
                perror("cd");
        else
        {
                _setenv(d, "OLDPWD", _getenv("PWD"));
                if (getcwd(cwd, sizeof(cwd)) == NULL)
                        perror("getcwd() error");
                _setenv(d, "PWD", cwd);
        }
}

