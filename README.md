# kodebin-lib
Simple library for my project

### Requirement
Zephir Lang (http://zephir-lang)
```php
sudo apt-get install git gcc make re2c php5 php5-json php5-dev libpcre3-dev
```

Tutorial install zephir :
http://docs.zephir-lang.com/en/latest/install.html#installing-zephir


### Install
```php
cd kodebin-lib
zephir build

echo "extension=kodebin.so" >> /etc/php5/apache2/php.ini
```

### Usage

```php
<?php
use Kodebin\Lib\Files;
use Kodebin\Lib\Folder;
use Kodebin\Security\Patch;
use Kodebin\Security\Password;


Files::create($location); // Create file
Files::read($location); // Read file
Files::replace($exist,$content,$output); // Replace or create other file

Folder::create($name); // Create folder

Patch::xss_escape($string); // XSS Security
Patch::lfi_escape($string); // LFI Security
Patch::sql_escape($string); // SQL Security

```
