namespace Kodebin\Lib;
 
class Dir {
 //BELUM BERHASIL!
	public static function tree(dir, dir_, files_) {
	var recursive;
	var listDirs;
	var listFiles;
	var exclude;
	var arrayItems;
	var skipByExclude;
	var handle;
	var skip;
	var file;
	let recursive = false;
	let listDirs = dir_;
	let listFiles = files_;
	let exclude = "";
    let skipByExclude = false;
    let handle = opendir(dir);
    if(handle){
    let file = readdir(handle);
    while(false !== (file)){
    //preg_match("/(^(([\.]){1,2})$|(\.(svn|git|render))|(Thumbs\.db|\.DS_STORE))$/iu", file, skip);
        if(exclude){
        //preg_match(exclude, file, skipByExclude);
        }
        if (!skip && !skipByExclude) {
                if (is_dir(dir. DIRECTORY_SEPARATOR . file)) {
                    if(recursive) {
                        //let arrayItems = [arrayItems, tree(dir. DIRECTORY_SEPARATOR . file, recursive, listDirs, listFiles, exclude)];
                    }
                    if(listDirs){
                        let file = file;
                        let arrayItems = [file];
                    }
                } else {
                    if(listFiles){
                        let file = file;
                        let arrayItems = [file];
                    }
                }
            }
        }
        closedir(handle);
        }
        return arrayItems;
    }
 
}
