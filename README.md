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
use Kodebin\Lib\Curl;
use Kodebin\Lib\Folder;
use Kodebin\Lib\Github;
use Kodebin\Security\Patch;
use Kodebin\Security\Password;


Github::markdown($markdown); // Render markdown with API Github

Password::md5_api($string); // Create MD5 for API
Password::md5_10($string); // Create MD5 with 10 char and with new logic

Files::create($location); // Create file
Files::read($location); // Read file
Files::replace($exist,$content,$output); // Replace or create other file
Files::extension($location); // Get Extension file
Files::size($location); // Get size file
Files::size_format($location); // Get size file and format to KB,MB,GB,TB

Folder::create($name); // Create folder

Patch::xss_escape($string); // XSS Security
Patch::lfi_escape($string); // LFI Security
Patch::sql_escape($string); // SQL Security

Curl::post($url, $data); // Curl POST , $data is array with json_encode or not
Curl::get($url, $data); // Curl GET, $url = http://google.com/ , $data = parameter

```
