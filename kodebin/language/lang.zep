namespace Kodebin\Language;
 
class Lang {

  public static function template(content) {
      var bahasa;
      var app;
      array text;
      let bahasa = substr($_SERVER["HTTP_ACCEPT_LANGUAGE"],0,2);
      let app = new Lang();
      if(bahasa == "indonesia"){
      
      }else{
        let text = [
          // Header
          "home": "Home",
          "explore": "Explore",
          "notification": "Notifications",
          "myprofile": "My profile",
          "settings": "Account settings",
          "create_repo": "Create repository",
          "help": "Help center",
          "logout": "Logout",
          "login": "Sign in",
          "register": "Sign up",
          // Footer
          "about": "About",
          "team": "Team",
          "blog": "Blog",
          "api": "API",
          // Explore
          "explore_des": "Search other open source project based on the available categories.",
          // Panel - Create Repo
          "create_repo_des": "Create new repository, or clone from Github and Bitbucket.",
          "repo_name": "Repository name",
          "repo_des": "Description",
          "repo_clone": "Clone from git",
          "repo_cat": "Category",
          "repo_lang": "Language",
          "repo_license": "License",
          //Panel - index
          "guide": "Guide",
          "guide_new_repo": "Create repository",
          "guide_mg_repo": "Manage repositories",
          "guide_cr": "Contribution project",
          "guide_work": "Work with team",
          "latest_activity": "Latest activity",
          "all": "All",
          "following": "Following",
          "your_repo": "Your repositories",
          "create_new_repo": "Create new repository",
          // Profile
          "joined": "Joined on",
          "followers": "Followers",
          "activity": "Public activity",
          "contribution": "Contribution",
          "repository": "Repositories",
          // Repository
          "download_zip": "Download ZIP",
          "new_folder": "New folder",
          "name_folder": "Folder name",
          "make_folder": "Create folder",
          "new_file": "New file",
          "name_file": "Filename",
          "make_file": "Create file",
          "new_pull": "New pull requests",
          // Auth
          "login_success": app->success_msg("Login success, you will redirect to panel."),
	        "login_error_1": app->error_msg("Username or password incorrect."),
          "register_success": app->success_msg("Register success, login to your account."),
          "register_error_1": app->error_msg("Register failed, try again!"),
	        "register_error_2": app->error_msg("Username or email already exist."),
	        "add_file_success": app->success_msg("File has been created."),
	        "add_file_error": app->error_msg("Please input filename!"),
	        "add_folder_success": app->success_msg("Folder has been created."),
          "add_folder_error": app->error_msg("Please input folder name!"),
          "create_repo_success": app->success_msg("Repository has been created."),
          "create_repo_error_1": app->error_msg("Repository already exist."),
          "create_repo_error_2": app->error_msg("Please input description."),
          "create_repo_error_3": app->error_msg("Please input repository name."),
          // Panel & profile activity
          "create_repo_mode": "create new a repository "
        
        ];
      }
      
  echo text[content];
  }
  
  public static function error_msg(content) {
  return "<div class='alert alert-danger' id='success-alert'>
	        <a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a>
          <strong>Failed!</strong> ".content."
	        </div>";
  }
  
  public static function success_msg(content) {
  return "<div class='alert alert-success' id='success-alert'>
	        <a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a>
          <strong>Success!</strong> ".content."
	        </div>";
  }
  
}
