



<!DOCTYPE html>
<html lang="en" class="">
  <head prefix="og: http://ogp.me/ns# fb: http://ogp.me/ns/fb# object: http://ogp.me/ns/object# article: http://ogp.me/ns/article# profile: http://ogp.me/ns/profile#">
    <meta charset='utf-8'>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta http-equiv="Content-Language" content="en">
    
    
    <title>no-OS/ADF7023.h at master · analogdevicesinc/no-OS · GitHub</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub">
    <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub">
    <link rel="apple-touch-icon" sizes="57x57" href="/apple-touch-icon-114.png">
    <link rel="apple-touch-icon" sizes="114x114" href="/apple-touch-icon-114.png">
    <link rel="apple-touch-icon" sizes="72x72" href="/apple-touch-icon-144.png">
    <link rel="apple-touch-icon" sizes="144x144" href="/apple-touch-icon-144.png">
    <meta property="fb:app_id" content="1401488693436528">

      <meta content="@github" name="twitter:site" /><meta content="summary" name="twitter:card" /><meta content="analogdevicesinc/no-OS" name="twitter:title" /><meta content="no-OS - Software drivers for systems without OS" name="twitter:description" /><meta content="https://avatars3.githubusercontent.com/u/2465527?v=3&amp;s=400" name="twitter:image:src" />
<meta content="GitHub" property="og:site_name" /><meta content="object" property="og:type" /><meta content="https://avatars3.githubusercontent.com/u/2465527?v=3&amp;s=400" property="og:image" /><meta content="analogdevicesinc/no-OS" property="og:title" /><meta content="https://github.com/analogdevicesinc/no-OS" property="og:url" /><meta content="no-OS - Software drivers for systems without OS" property="og:description" />

      <meta name="browser-stats-url" content="/_stats">
    <link rel="assets" href="https://assets-cdn.github.com/">
    <link rel="conduit-xhr" href="https://ghconduit.com:25035">
    
    <meta name="pjax-timeout" content="1000">
    

    <meta name="msapplication-TileImage" content="/windows-tile.png">
    <meta name="msapplication-TileColor" content="#ffffff">
    <meta name="selected-link" value="repo_source" data-pjax-transient>
      <meta name="google-analytics" content="UA-3769691-2">

    <meta content="collector.githubapp.com" name="octolytics-host" /><meta content="collector-cdn.github.com" name="octolytics-script-host" /><meta content="github" name="octolytics-app-id" /><meta content="12F20790:5F99:1BB4ED95:546EDF89" name="octolytics-dimension-request_id" />
    
    <meta content="Rails, view, blob#show" name="analytics-event" />

    
    
    <link rel="icon" type="image/x-icon" href="https://assets-cdn.github.com/favicon.ico">


    <meta content="authenticity_token" name="csrf-param" />
<meta content="SFS9hWyS7vERsCwFLzKMeM1s78Wlu3pApaEkdfYCgCP1m9YgMrJiwtOXkGgGq7cbXTJqwrwpgWn2XCE4Z9tZVw==" name="csrf-token" />

    <link href="https://assets-cdn.github.com/assets/github-fa9b8c5d848205db514d4097d2b78f4528d01a79f39601e0f9c5c40ed6894711.css" media="all" rel="stylesheet" type="text/css" />
    <link href="https://assets-cdn.github.com/assets/github2-e48cf9f7b34f2138837ae8f236223b114441dde478e265f64e1ad9bf6bd76afd.css" media="all" rel="stylesheet" type="text/css" />
    
    


    <meta http-equiv="x-pjax-version" content="4bd1158cb0b6a7536ceeee1c74a448f2">

      
  <meta name="description" content="no-OS - Software drivers for systems without OS">
  <meta name="go-import" content="github.com/analogdevicesinc/no-OS git https://github.com/analogdevicesinc/no-OS.git">

  <meta content="2465527" name="octolytics-dimension-user_id" /><meta content="analogdevicesinc" name="octolytics-dimension-user_login" /><meta content="7014478" name="octolytics-dimension-repository_id" /><meta content="analogdevicesinc/no-OS" name="octolytics-dimension-repository_nwo" /><meta content="true" name="octolytics-dimension-repository_public" /><meta content="false" name="octolytics-dimension-repository_is_fork" /><meta content="7014478" name="octolytics-dimension-repository_network_root_id" /><meta content="analogdevicesinc/no-OS" name="octolytics-dimension-repository_network_root_nwo" />
  <link href="https://github.com/analogdevicesinc/no-OS/commits/master.atom" rel="alternate" title="Recent Commits to no-OS:master" type="application/atom+xml">

  </head>


  <body class="logged_out  env-production windows vis-public page-blob">
    <a href="#start-of-content" tabindex="1" class="accessibility-aid js-skip-to-content">Skip to content</a>
    <div class="wrapper">
      
      
      
      


      
      <div class="header header-logged-out" role="banner">
  <div class="container clearfix">

    <a class="header-logo-wordmark" href="https://github.com/" ga-data-click="(Logged out) Header, go to homepage, icon:logo-wordmark">
      <span class="mega-octicon octicon-logo-github"></span>
    </a>

    <div class="header-actions" role="navigation">
        <a class="button primary" href="/join" data-ga-click="(Logged out) Header, clicked Sign up, text:sign-up">Sign up</a>
      <a class="button signin" href="/login?return_to=%2Fanalogdevicesinc%2Fno-OS%2Fblob%2Fmaster%2Fdrivers%2FADF7023%2FADF7023.h" data-ga-click="(Logged out) Header, clicked Sign in, text:sign-in">Sign in</a>
    </div>

    <div class="site-search repo-scope js-site-search" role="search">
      <form accept-charset="UTF-8" action="/analogdevicesinc/no-OS/search" class="js-site-search-form" data-global-search-url="/search" data-repo-search-url="/analogdevicesinc/no-OS/search" method="get"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /></div>
  <input type="text"
    class="js-site-search-field is-clearable"
    data-hotkey="s"
    name="q"
    placeholder="Search"
    data-global-scope-placeholder="Search GitHub"
    data-repo-scope-placeholder="Search"
    tabindex="1"
    autocapitalize="off">
  <div class="scope-badge">This repository</div>
</form>
    </div>

      <ul class="header-nav left" role="navigation">
          <li class="header-nav-item">
            <a class="header-nav-link" href="/explore" data-ga-click="(Logged out) Header, go to explore, text:explore">Explore</a>
          </li>
          <li class="header-nav-item">
            <a class="header-nav-link" href="/features" data-ga-click="(Logged out) Header, go to features, text:features">Features</a>
          </li>
          <li class="header-nav-item">
            <a class="header-nav-link" href="https://enterprise.github.com/" data-ga-click="(Logged out) Header, go to enterprise, text:enterprise">Enterprise</a>
          </li>
          <li class="header-nav-item">
            <a class="header-nav-link" href="/blog" data-ga-click="(Logged out) Header, go to blog, text:blog">Blog</a>
          </li>
      </ul>

  </div>
</div>



      <div id="start-of-content" class="accessibility-aid"></div>
          <div class="site" itemscope itemtype="http://schema.org/WebPage">
    <div id="js-flash-container">
      
    </div>
    <div class="pagehead repohead instapaper_ignore readability-menu">
      <div class="container">
        
<ul class="pagehead-actions">


  <li>
      <a href="/login?return_to=%2Fanalogdevicesinc%2Fno-OS"
    class="minibutton with-count star-button tooltipped tooltipped-n"
    aria-label="You must be signed in to star a repository" rel="nofollow">
    <span class="octicon octicon-star"></span>
    Star
  </a>

    <a class="social-count js-social-count" href="/analogdevicesinc/no-OS/stargazers">
      24
    </a>

  </li>

    <li>
      <a href="/login?return_to=%2Fanalogdevicesinc%2Fno-OS"
        class="minibutton with-count js-toggler-target fork-button tooltipped tooltipped-n"
        aria-label="You must be signed in to fork a repository" rel="nofollow">
        <span class="octicon octicon-repo-forked"></span>
        Fork
      </a>
      <a href="/analogdevicesinc/no-OS/network" class="social-count">
        211
      </a>
    </li>
</ul>

        <h1 itemscope itemtype="http://data-vocabulary.org/Breadcrumb" class="entry-title public">
          <span class="mega-octicon octicon-repo"></span>
          <span class="author"><a href="/analogdevicesinc" class="url fn" itemprop="url" rel="author"><span itemprop="title">analogdevicesinc</span></a></span><!--
       --><span class="path-divider">/</span><!--
       --><strong><a href="/analogdevicesinc/no-OS" class="js-current-repository" data-pjax="#js-repo-pjax-container">no-OS</a></strong>

          <span class="page-context-loader">
            <img alt="" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
          </span>

        </h1>
      </div><!-- /.container -->
    </div><!-- /.repohead -->

    <div class="container">
      <div class="repository-with-sidebar repo-container new-discussion-timeline  ">
        <div class="repository-sidebar clearfix">
            
<nav class="sunken-menu repo-nav js-repo-nav js-sidenav-container-pjax js-octicon-loaders"
     role="navigation"
     data-pjax="#js-repo-pjax-container"
     data-issue-count-url="/analogdevicesinc/no-OS/issues/counts">
  <ul class="sunken-menu-group">
    <li class="tooltipped tooltipped-w" aria-label="Code">
      <a href="/analogdevicesinc/no-OS" aria-label="Code" class="selected js-selected-navigation-item sunken-menu-item" data-hotkey="g c" data-selected-links="repo_source repo_downloads repo_commits repo_releases repo_tags repo_branches /analogdevicesinc/no-OS">
        <span class="octicon octicon-code"></span> <span class="full-word">Code</span>
        <img alt="" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>    </li>

      <li class="tooltipped tooltipped-w" aria-label="Issues">
        <a href="/analogdevicesinc/no-OS/issues" aria-label="Issues" class="js-selected-navigation-item sunken-menu-item" data-hotkey="g i" data-selected-links="repo_issues repo_labels repo_milestones /analogdevicesinc/no-OS/issues">
          <span class="octicon octicon-issue-opened"></span> <span class="full-word">Issues</span>
          <span class="js-issue-replace-counter"></span>
          <img alt="" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>

    <li class="tooltipped tooltipped-w" aria-label="Pull Requests">
      <a href="/analogdevicesinc/no-OS/pulls" aria-label="Pull Requests" class="js-selected-navigation-item sunken-menu-item" data-hotkey="g p" data-selected-links="repo_pulls /analogdevicesinc/no-OS/pulls">
          <span class="octicon octicon-git-pull-request"></span> <span class="full-word">Pull Requests</span>
          <span class="js-pull-replace-counter"></span>
          <img alt="" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>    </li>


      <li class="tooltipped tooltipped-w" aria-label="Wiki">
        <a href="/analogdevicesinc/no-OS/wiki" aria-label="Wiki" class="js-selected-navigation-item sunken-menu-item" data-hotkey="g w" data-selected-links="repo_wiki /analogdevicesinc/no-OS/wiki">
          <span class="octicon octicon-book"></span> <span class="full-word">Wiki</span>
          <img alt="" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>
  </ul>
  <div class="sunken-menu-separator"></div>
  <ul class="sunken-menu-group">

    <li class="tooltipped tooltipped-w" aria-label="Pulse">
      <a href="/analogdevicesinc/no-OS/pulse" aria-label="Pulse" class="js-selected-navigation-item sunken-menu-item" data-selected-links="pulse /analogdevicesinc/no-OS/pulse">
        <span class="octicon octicon-pulse"></span> <span class="full-word">Pulse</span>
        <img alt="" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>    </li>

    <li class="tooltipped tooltipped-w" aria-label="Graphs">
      <a href="/analogdevicesinc/no-OS/graphs" aria-label="Graphs" class="js-selected-navigation-item sunken-menu-item" data-selected-links="repo_graphs repo_contributors /analogdevicesinc/no-OS/graphs">
        <span class="octicon octicon-graph"></span> <span class="full-word">Graphs</span>
        <img alt="" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>    </li>
  </ul>


</nav>

              <div class="only-with-full-nav">
                
  
<div class="clone-url open"
  data-protocol-type="http"
  data-url="/users/set_protocol?protocol_selector=http&amp;protocol_type=clone">
  <h3><span class="text-emphasized">HTTPS</span> clone URL</h3>
  <div class="input-group">
    <input type="text" class="input-mini input-monospace js-url-field"
           value="https://github.com/analogdevicesinc/no-OS.git" readonly="readonly">
    <span class="input-group-button">
      <button aria-label="Copy to clipboard" class="js-zeroclipboard minibutton zeroclipboard-button" data-clipboard-text="https://github.com/analogdevicesinc/no-OS.git" data-copied-hint="Copied!" type="button"><span class="octicon octicon-clippy"></span></button>
    </span>
  </div>
</div>

  
<div class="clone-url "
  data-protocol-type="subversion"
  data-url="/users/set_protocol?protocol_selector=subversion&amp;protocol_type=clone">
  <h3><span class="text-emphasized">Subversion</span> checkout URL</h3>
  <div class="input-group">
    <input type="text" class="input-mini input-monospace js-url-field"
           value="https://github.com/analogdevicesinc/no-OS" readonly="readonly">
    <span class="input-group-button">
      <button aria-label="Copy to clipboard" class="js-zeroclipboard minibutton zeroclipboard-button" data-clipboard-text="https://github.com/analogdevicesinc/no-OS" data-copied-hint="Copied!" type="button"><span class="octicon octicon-clippy"></span></button>
    </span>
  </div>
</div>


<p class="clone-options">You can clone with
      <a href="#" class="js-clone-selector" data-protocol="http">HTTPS</a>
      or <a href="#" class="js-clone-selector" data-protocol="subversion">Subversion</a>.
  <a href="https://help.github.com/articles/which-remote-url-should-i-use" class="help tooltipped tooltipped-n" aria-label="Get help on which URL is right for you.">
    <span class="octicon octicon-question"></span>
  </a>
</p>


  <a href="http://windows.github.com" class="minibutton sidebar-button" title="Save analogdevicesinc/no-OS to your computer and use it in GitHub Desktop." aria-label="Save analogdevicesinc/no-OS to your computer and use it in GitHub Desktop.">
    <span class="octicon octicon-device-desktop"></span>
    Clone in Desktop
  </a>

                <a href="/analogdevicesinc/no-OS/archive/master.zip"
                   class="minibutton sidebar-button"
                   aria-label="Download the contents of analogdevicesinc/no-OS as a zip file"
                   title="Download the contents of analogdevicesinc/no-OS as a zip file"
                   rel="nofollow">
                  <span class="octicon octicon-cloud-download"></span>
                  Download ZIP
                </a>
              </div>
        </div><!-- /.repository-sidebar -->

        <div id="js-repo-pjax-container" class="repository-content context-loader-container" data-pjax-container>
          

<a href="/analogdevicesinc/no-OS/blob/fa3cffa3b54a10174e0aa2519bdbb5cd8eab5978/drivers/ADF7023/ADF7023.h" class="hidden js-permalink-shortcut" data-hotkey="y">Permalink</a>

<!-- blob contrib key: blob_contributors:v21:971169ea2f04d9499eb1ec4e0142c436 -->

<div class="file-navigation">
  
<div class="select-menu js-menu-container js-select-menu left">
  <span class="minibutton select-menu-button js-menu-target css-truncate" data-hotkey="w"
    data-master-branch="master"
    data-ref="master"
    title="master"
    role="button" aria-label="Switch branches or tags" tabindex="0" aria-haspopup="true">
    <span class="octicon octicon-git-branch"></span>
    <i>branch:</i>
    <span class="js-select-button css-truncate-target">master</span>
  </span>

  <div class="select-menu-modal-holder js-menu-content js-navigation-container" data-pjax aria-hidden="true">

    <div class="select-menu-modal">
      <div class="select-menu-header">
        <span class="select-menu-title">Switch branches/tags</span>
        <span class="octicon octicon-x js-menu-close" role="button" aria-label="Close"></span>
      </div> <!-- /.select-menu-header -->

      <div class="select-menu-filters">
        <div class="select-menu-text-filter">
          <input type="text" aria-label="Filter branches/tags" id="context-commitish-filter-field" class="js-filterable-field js-navigation-enable" placeholder="Filter branches/tags">
        </div>
        <div class="select-menu-tabs">
          <ul>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="branches" class="js-select-menu-tab">Branches</a>
            </li>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="tags" class="js-select-menu-tab">Tags</a>
            </li>
          </ul>
        </div><!-- /.select-menu-tabs -->
      </div><!-- /.select-menu-filters -->

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="branches">

        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/analogdevicesinc/no-OS/blob/2014_R1/drivers/ADF7023/ADF7023.h"
                 data-name="2014_R1"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2014_R1">2014_R1</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/analogdevicesinc/no-OS/blob/gh-pages/drivers/ADF7023/ADF7023.h"
                 data-name="gh-pages"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="gh-pages">gh-pages</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item selected">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/analogdevicesinc/no-OS/blob/master/drivers/ADF7023/ADF7023.h"
                 data-name="master"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="master">master</a>
            </div> <!-- /.select-menu-item -->
        </div>

          <div class="select-menu-no-results">Nothing to show</div>
      </div> <!-- /.select-menu-list -->

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="tags">
        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/analogdevicesinc/no-OS/tree/fmcomms1_ver_1_09_13_2013/drivers/ADF7023/ADF7023.h"
                 data-name="fmcomms1_ver_1_09_13_2013"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="fmcomms1_ver_1_09_13_2013">fmcomms1_ver_1_09_13_2013</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/analogdevicesinc/no-OS/tree/fmcomms1_07_09_2013/drivers/ADF7023/ADF7023.h"
                 data-name="fmcomms1_07_09_2013"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="fmcomms1_07_09_2013">fmcomms1_07_09_2013</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/analogdevicesinc/no-OS/tree/fmcomms1_05_01_2013/drivers/ADF7023/ADF7023.h"
                 data-name="fmcomms1_05_01_2013"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="fmcomms1_05_01_2013">fmcomms1_05_01_2013</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/analogdevicesinc/no-OS/tree/fmcomms1_03_27_2013/drivers/ADF7023/ADF7023.h"
                 data-name="fmcomms1_03_27_2013"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="fmcomms1_03_27_2013">fmcomms1_03_27_2013</a>
            </div> <!-- /.select-menu-item -->
        </div>

        <div class="select-menu-no-results">Nothing to show</div>
      </div> <!-- /.select-menu-list -->

    </div> <!-- /.select-menu-modal -->
  </div> <!-- /.select-menu-modal-holder -->
</div> <!-- /.select-menu -->

  <div class="button-group right">
    <a href="/analogdevicesinc/no-OS/find/master"
          class="js-show-file-finder minibutton empty-icon tooltipped tooltipped-s"
          data-pjax
          data-hotkey="t"
          aria-label="Quickly jump between files">
      <span class="octicon octicon-list-unordered"></span>
    </a>
    <button aria-label="Copy to clipboard" class="js-zeroclipboard minibutton zeroclipboard-button" data-clipboard-text="drivers/ADF7023/ADF7023.h" data-copied-hint="Copied!" type="button"><span class="octicon octicon-clippy"></span></button>
  </div>

  <div class="breadcrumb">
    <span class='repo-root js-repo-root'><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/analogdevicesinc/no-OS" class="" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">no-OS</span></a></span></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/analogdevicesinc/no-OS/tree/master/drivers" class="" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">drivers</span></a></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/analogdevicesinc/no-OS/tree/master/drivers/ADF7023" class="" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">ADF7023</span></a></span><span class="separator"> / </span><strong class="final-path">ADF7023.h</strong>
  </div>
</div>


  <div class="commit file-history-tease">
    <div class="file-history-tease-header">
        <img alt="dbogdan" class="avatar" data-user="1921873" height="24" src="https://avatars1.githubusercontent.com/u/1921873?v=3&amp;s=48" width="24" />
        <span class="author"><a href="/dbogdan" rel="contributor">dbogdan</a></span>
        <time datetime="2013-05-20T16:05:41Z" is="relative-time">May 20, 2013</time>
        <div class="commit-title">
            <a href="/analogdevicesinc/no-OS/commit/87bff90e063a30e5f4651edbecb6a9d81a918a1a" class="message" data-pjax="true" title="Added 3 more functions.">Added 3 more functions.</a>
        </div>
    </div>

    <div class="participation">
      <p class="quickstat">
        <a href="#blob_contributors_box" rel="facebox">
          <strong>1</strong>
           contributor
        </a>
      </p>
      
    </div>
    <div id="blob_contributors_box" style="display:none">
      <h2 class="facebox-header">Users who have contributed to this file</h2>
      <ul class="facebox-user-list">
          <li class="facebox-user-list-item">
            <img alt="dbogdan" data-user="1921873" height="24" src="https://avatars1.githubusercontent.com/u/1921873?v=3&amp;s=48" width="24" />
            <a href="/dbogdan">dbogdan</a>
          </li>
      </ul>
    </div>
  </div>

<div class="file-box">
  <div class="file">
    <div class="meta clearfix">
      <div class="info file-name">
          <span>411 lines (373 sloc)</span>
          <span class="meta-divider"></span>
        <span>21.295 kb</span>
      </div>
      <div class="actions">
        <div class="button-group">
          <a href="/analogdevicesinc/no-OS/raw/master/drivers/ADF7023/ADF7023.h" class="minibutton " id="raw-url">Raw</a>
            <a href="/analogdevicesinc/no-OS/blame/master/drivers/ADF7023/ADF7023.h" class="minibutton js-update-url-with-hash">Blame</a>
          <a href="/analogdevicesinc/no-OS/commits/master/drivers/ADF7023/ADF7023.h" class="minibutton " rel="nofollow">History</a>
        </div><!-- /.button-group -->

          <a class="octicon-button tooltipped tooltipped-nw"
             href="http://windows.github.com" aria-label="Open this file in GitHub for Windows">
              <span class="octicon octicon-device-desktop"></span>
          </a>

            <a class="octicon-button disabled tooltipped tooltipped-w" href="#"
               aria-label="You must be signed in to make or propose changes"><span class="octicon octicon-pencil"></span></a>

          <a class="octicon-button danger disabled tooltipped tooltipped-w" href="#"
             aria-label="You must be signed in to make or propose changes">
          <span class="octicon octicon-trashcan"></span>
        </a>
      </div><!-- /.actions -->
    </div>
    

  <div class="blob-wrapper data type-c">
      <table class="highlight tab-size-8 js-file-line-container">
      <tr>
        <td id="L1" class="blob-num js-line-number" data-line-number="1"></td>
        <td id="LC1" class="blob-code js-file-line"><span class="pl-c">/***************************************************************************//**</span></td>
      </tr>
      <tr>
        <td id="L2" class="blob-num js-line-number" data-line-number="2"></td>
        <td id="LC2" class="blob-code js-file-line"><span class="pl-c"> *   @file   ADF7023.h</span></td>
      </tr>
      <tr>
        <td id="L3" class="blob-num js-line-number" data-line-number="3"></td>
        <td id="LC3" class="blob-code js-file-line"><span class="pl-c"> *   @brief  Header file of ADF7023 Driver.</span></td>
      </tr>
      <tr>
        <td id="L4" class="blob-num js-line-number" data-line-number="4"></td>
        <td id="LC4" class="blob-code js-file-line"><span class="pl-c"> *   @author DBogdan (Dragos.Bogdan@analog.com)</span></td>
      </tr>
      <tr>
        <td id="L5" class="blob-num js-line-number" data-line-number="5"></td>
        <td id="LC5" class="blob-code js-file-line"><span class="pl-c">********************************************************************************</span></td>
      </tr>
      <tr>
        <td id="L6" class="blob-num js-line-number" data-line-number="6"></td>
        <td id="LC6" class="blob-code js-file-line"><span class="pl-c"> * Copyright 2013(c) Analog Devices, Inc.</span></td>
      </tr>
      <tr>
        <td id="L7" class="blob-num js-line-number" data-line-number="7"></td>
        <td id="LC7" class="blob-code js-file-line"><span class="pl-c"> *</span></td>
      </tr>
      <tr>
        <td id="L8" class="blob-num js-line-number" data-line-number="8"></td>
        <td id="LC8" class="blob-code js-file-line"><span class="pl-c"> * All rights reserved.</span></td>
      </tr>
      <tr>
        <td id="L9" class="blob-num js-line-number" data-line-number="9"></td>
        <td id="LC9" class="blob-code js-file-line"><span class="pl-c"> *</span></td>
      </tr>
      <tr>
        <td id="L10" class="blob-num js-line-number" data-line-number="10"></td>
        <td id="LC10" class="blob-code js-file-line"><span class="pl-c"> * Redistribution and use in source and binary forms, with or without</span></td>
      </tr>
      <tr>
        <td id="L11" class="blob-num js-line-number" data-line-number="11"></td>
        <td id="LC11" class="blob-code js-file-line"><span class="pl-c"> * modification, are permitted provided that the following conditions are met:</span></td>
      </tr>
      <tr>
        <td id="L12" class="blob-num js-line-number" data-line-number="12"></td>
        <td id="LC12" class="blob-code js-file-line"><span class="pl-c"> *  - Redistributions of source code must retain the above copyright</span></td>
      </tr>
      <tr>
        <td id="L13" class="blob-num js-line-number" data-line-number="13"></td>
        <td id="LC13" class="blob-code js-file-line"><span class="pl-c"> *    notice, this list of conditions and the following disclaimer.</span></td>
      </tr>
      <tr>
        <td id="L14" class="blob-num js-line-number" data-line-number="14"></td>
        <td id="LC14" class="blob-code js-file-line"><span class="pl-c"> *  - Redistributions in binary form must reproduce the above copyright</span></td>
      </tr>
      <tr>
        <td id="L15" class="blob-num js-line-number" data-line-number="15"></td>
        <td id="LC15" class="blob-code js-file-line"><span class="pl-c"> *    notice, this list of conditions and the following disclaimer in</span></td>
      </tr>
      <tr>
        <td id="L16" class="blob-num js-line-number" data-line-number="16"></td>
        <td id="LC16" class="blob-code js-file-line"><span class="pl-c"> *    the documentation and/or other materials provided with the</span></td>
      </tr>
      <tr>
        <td id="L17" class="blob-num js-line-number" data-line-number="17"></td>
        <td id="LC17" class="blob-code js-file-line"><span class="pl-c"> *    distribution.</span></td>
      </tr>
      <tr>
        <td id="L18" class="blob-num js-line-number" data-line-number="18"></td>
        <td id="LC18" class="blob-code js-file-line"><span class="pl-c"> *  - Neither the name of Analog Devices, Inc. nor the names of its</span></td>
      </tr>
      <tr>
        <td id="L19" class="blob-num js-line-number" data-line-number="19"></td>
        <td id="LC19" class="blob-code js-file-line"><span class="pl-c"> *    contributors may be used to endorse or promote products derived</span></td>
      </tr>
      <tr>
        <td id="L20" class="blob-num js-line-number" data-line-number="20"></td>
        <td id="LC20" class="blob-code js-file-line"><span class="pl-c"> *    from this software without specific prior written permission.</span></td>
      </tr>
      <tr>
        <td id="L21" class="blob-num js-line-number" data-line-number="21"></td>
        <td id="LC21" class="blob-code js-file-line"><span class="pl-c"> *  - The use of this software may or may not infringe the patent rights</span></td>
      </tr>
      <tr>
        <td id="L22" class="blob-num js-line-number" data-line-number="22"></td>
        <td id="LC22" class="blob-code js-file-line"><span class="pl-c"> *    of one or more patent holders.  This license does not release you</span></td>
      </tr>
      <tr>
        <td id="L23" class="blob-num js-line-number" data-line-number="23"></td>
        <td id="LC23" class="blob-code js-file-line"><span class="pl-c"> *    from the requirement that you obtain separate licenses from these</span></td>
      </tr>
      <tr>
        <td id="L24" class="blob-num js-line-number" data-line-number="24"></td>
        <td id="LC24" class="blob-code js-file-line"><span class="pl-c"> *    patent holders to use this software.</span></td>
      </tr>
      <tr>
        <td id="L25" class="blob-num js-line-number" data-line-number="25"></td>
        <td id="LC25" class="blob-code js-file-line"><span class="pl-c"> *  - Use of the software either in source or binary form, must be run</span></td>
      </tr>
      <tr>
        <td id="L26" class="blob-num js-line-number" data-line-number="26"></td>
        <td id="LC26" class="blob-code js-file-line"><span class="pl-c"> *    on or directly connected to an Analog Devices Inc. component.</span></td>
      </tr>
      <tr>
        <td id="L27" class="blob-num js-line-number" data-line-number="27"></td>
        <td id="LC27" class="blob-code js-file-line"><span class="pl-c"> *</span></td>
      </tr>
      <tr>
        <td id="L28" class="blob-num js-line-number" data-line-number="28"></td>
        <td id="LC28" class="blob-code js-file-line"><span class="pl-c"> * THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES &quot;AS IS&quot; AND ANY EXPRESS OR</span></td>
      </tr>
      <tr>
        <td id="L29" class="blob-num js-line-number" data-line-number="29"></td>
        <td id="LC29" class="blob-code js-file-line"><span class="pl-c"> * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT,</span></td>
      </tr>
      <tr>
        <td id="L30" class="blob-num js-line-number" data-line-number="30"></td>
        <td id="LC30" class="blob-code js-file-line"><span class="pl-c"> * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.</span></td>
      </tr>
      <tr>
        <td id="L31" class="blob-num js-line-number" data-line-number="31"></td>
        <td id="LC31" class="blob-code js-file-line"><span class="pl-c"> * IN NO EVENT SHALL ANALOG DEVICES BE LIABLE FOR ANY DIRECT, INDIRECT,</span></td>
      </tr>
      <tr>
        <td id="L32" class="blob-num js-line-number" data-line-number="32"></td>
        <td id="LC32" class="blob-code js-file-line"><span class="pl-c"> * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT</span></td>
      </tr>
      <tr>
        <td id="L33" class="blob-num js-line-number" data-line-number="33"></td>
        <td id="LC33" class="blob-code js-file-line"><span class="pl-c"> * LIMITED TO, INTELLECTUAL PROPERTY RIGHTS, PROCUREMENT OF SUBSTITUTE GOODS OR</span></td>
      </tr>
      <tr>
        <td id="L34" class="blob-num js-line-number" data-line-number="34"></td>
        <td id="LC34" class="blob-code js-file-line"><span class="pl-c"> * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER</span></td>
      </tr>
      <tr>
        <td id="L35" class="blob-num js-line-number" data-line-number="35"></td>
        <td id="LC35" class="blob-code js-file-line"><span class="pl-c"> * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,</span></td>
      </tr>
      <tr>
        <td id="L36" class="blob-num js-line-number" data-line-number="36"></td>
        <td id="LC36" class="blob-code js-file-line"><span class="pl-c"> * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE</span></td>
      </tr>
      <tr>
        <td id="L37" class="blob-num js-line-number" data-line-number="37"></td>
        <td id="LC37" class="blob-code js-file-line"><span class="pl-c"> * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.</span></td>
      </tr>
      <tr>
        <td id="L38" class="blob-num js-line-number" data-line-number="38"></td>
        <td id="LC38" class="blob-code js-file-line"><span class="pl-c"> *</span></td>
      </tr>
      <tr>
        <td id="L39" class="blob-num js-line-number" data-line-number="39"></td>
        <td id="LC39" class="blob-code js-file-line"><span class="pl-c">********************************************************************************</span></td>
      </tr>
      <tr>
        <td id="L40" class="blob-num js-line-number" data-line-number="40"></td>
        <td id="LC40" class="blob-code js-file-line"><span class="pl-c"> *   SVN Revision: $WCREV$</span></td>
      </tr>
      <tr>
        <td id="L41" class="blob-num js-line-number" data-line-number="41"></td>
        <td id="LC41" class="blob-code js-file-line"><span class="pl-c">*******************************************************************************/</span></td>
      </tr>
      <tr>
        <td id="L42" class="blob-num js-line-number" data-line-number="42"></td>
        <td id="LC42" class="blob-code js-file-line">#<span class="pl-k">ifndef</span> __ADF7023_H__</td>
      </tr>
      <tr>
        <td id="L43" class="blob-num js-line-number" data-line-number="43"></td>
        <td id="LC43" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">__ADF7023_H__</span></td>
      </tr>
      <tr>
        <td id="L44" class="blob-num js-line-number" data-line-number="44"></td>
        <td id="LC44" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L45" class="blob-num js-line-number" data-line-number="45"></td>
        <td id="LC45" class="blob-code js-file-line"><span class="pl-c">/* Status Word */</span></td>
      </tr>
      <tr>
        <td id="L46" class="blob-num js-line-number" data-line-number="46"></td>
        <td id="LC46" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">STATUS_SPI_READY</span>  (0x1 &lt;&lt; <span class="pl-c1">7</span>)</td>
      </tr>
      <tr>
        <td id="L47" class="blob-num js-line-number" data-line-number="47"></td>
        <td id="LC47" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">STATUS_IRQ_STATUS</span> (0x1 &lt;&lt; <span class="pl-c1">6</span>)</td>
      </tr>
      <tr>
        <td id="L48" class="blob-num js-line-number" data-line-number="48"></td>
        <td id="LC48" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">STATUS_CMD_READY</span>  (0x1 &lt;&lt; <span class="pl-c1">5</span>)</td>
      </tr>
      <tr>
        <td id="L49" class="blob-num js-line-number" data-line-number="49"></td>
        <td id="LC49" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">STATUS_FW_STATE</span>   (0x1F &lt;&lt; <span class="pl-c1">0</span>)</td>
      </tr>
      <tr>
        <td id="L50" class="blob-num js-line-number" data-line-number="50"></td>
        <td id="LC50" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L51" class="blob-num js-line-number" data-line-number="51"></td>
        <td id="LC51" class="blob-code js-file-line"><span class="pl-c">/* FW_STATE Description */</span></td>
      </tr>
      <tr>
        <td id="L52" class="blob-num js-line-number" data-line-number="52"></td>
        <td id="LC52" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">FW_STATE_INIT</span>             0x0F</td>
      </tr>
      <tr>
        <td id="L53" class="blob-num js-line-number" data-line-number="53"></td>
        <td id="LC53" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">FW_STATE_BUSY</span>             0x00</td>
      </tr>
      <tr>
        <td id="L54" class="blob-num js-line-number" data-line-number="54"></td>
        <td id="LC54" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">FW_STATE_PHY_OFF</span>          0x11</td>
      </tr>
      <tr>
        <td id="L55" class="blob-num js-line-number" data-line-number="55"></td>
        <td id="LC55" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">FW_STATE_PHY_ON</span>           0x12</td>
      </tr>
      <tr>
        <td id="L56" class="blob-num js-line-number" data-line-number="56"></td>
        <td id="LC56" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">FW_STATE_PHY_RX</span>           0x13</td>
      </tr>
      <tr>
        <td id="L57" class="blob-num js-line-number" data-line-number="57"></td>
        <td id="LC57" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">FW_STATE_PHY_TX</span>           0x14</td>
      </tr>
      <tr>
        <td id="L58" class="blob-num js-line-number" data-line-number="58"></td>
        <td id="LC58" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">FW_STATE_PHY_SLEEP</span>        0x06</td>
      </tr>
      <tr>
        <td id="L59" class="blob-num js-line-number" data-line-number="59"></td>
        <td id="LC59" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">FW_STATE_GET_RSSI</span>         0x05</td>
      </tr>
      <tr>
        <td id="L60" class="blob-num js-line-number" data-line-number="60"></td>
        <td id="LC60" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">FW_STATE_IR_CAL</span>           0x07</td>
      </tr>
      <tr>
        <td id="L61" class="blob-num js-line-number" data-line-number="61"></td>
        <td id="LC61" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">FW_STATE_AES_DECRYPT_INIT</span> 0x08</td>
      </tr>
      <tr>
        <td id="L62" class="blob-num js-line-number" data-line-number="62"></td>
        <td id="LC62" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">FW_STATE_AES_DECRYPT</span>      0x09</td>
      </tr>
      <tr>
        <td id="L63" class="blob-num js-line-number" data-line-number="63"></td>
        <td id="LC63" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">FW_STATE_AES_ENCRYPT</span>      0x0A</td>
      </tr>
      <tr>
        <td id="L64" class="blob-num js-line-number" data-line-number="64"></td>
        <td id="LC64" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L65" class="blob-num js-line-number" data-line-number="65"></td>
        <td id="LC65" class="blob-code js-file-line"><span class="pl-c">/* SPI Memory Access Commands */</span></td>
      </tr>
      <tr>
        <td id="L66" class="blob-num js-line-number" data-line-number="66"></td>
        <td id="LC66" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">SPI_MEM_WR</span>  0x18 <span class="pl-c">// Write data to packet RAM sequentially.</span></td>
      </tr>
      <tr>
        <td id="L67" class="blob-num js-line-number" data-line-number="67"></td>
        <td id="LC67" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">SPI_MEM_RD</span>  0x38 <span class="pl-c">// Read data from packet RAM sequentially.</span></td>
      </tr>
      <tr>
        <td id="L68" class="blob-num js-line-number" data-line-number="68"></td>
        <td id="LC68" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">SPI_MEMR_WR</span> 0x08 <span class="pl-c">// Write data to packet RAM nonsequentially.</span></td>
      </tr>
      <tr>
        <td id="L69" class="blob-num js-line-number" data-line-number="69"></td>
        <td id="LC69" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">SPI_MEMR_RD</span> 0x28 <span class="pl-c">// Read data from packet RAM nonsequentially.</span></td>
      </tr>
      <tr>
        <td id="L70" class="blob-num js-line-number" data-line-number="70"></td>
        <td id="LC70" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">SPI_NOP</span>     0xFF <span class="pl-c">// No operation.</span></td>
      </tr>
      <tr>
        <td id="L71" class="blob-num js-line-number" data-line-number="71"></td>
        <td id="LC71" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L72" class="blob-num js-line-number" data-line-number="72"></td>
        <td id="LC72" class="blob-code js-file-line"><span class="pl-c">/* Radio Controller Commands */</span></td>
      </tr>
      <tr>
        <td id="L73" class="blob-num js-line-number" data-line-number="73"></td>
        <td id="LC73" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">CMD_SYNC</span>             0xA2 <span class="pl-c">// This is an optional command. It is not necessary to use it during device initialization</span></td>
      </tr>
      <tr>
        <td id="L74" class="blob-num js-line-number" data-line-number="74"></td>
        <td id="LC74" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">CMD_PHY_OFF</span>          0xB0 <span class="pl-c">// Performs a transition of the device into the PHY_OFF state.</span></td>
      </tr>
      <tr>
        <td id="L75" class="blob-num js-line-number" data-line-number="75"></td>
        <td id="LC75" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">CMD_PHY_ON</span>           0xB1 <span class="pl-c">// Performs a transition of the device into the PHY_ON state.</span></td>
      </tr>
      <tr>
        <td id="L76" class="blob-num js-line-number" data-line-number="76"></td>
        <td id="LC76" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">CMD_PHY_RX</span>           0xB2 <span class="pl-c">// Performs a transition of the device into the PHY_RX state.</span></td>
      </tr>
      <tr>
        <td id="L77" class="blob-num js-line-number" data-line-number="77"></td>
        <td id="LC77" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">CMD_PHY_TX</span>           0xB5 <span class="pl-c">// Performs a transition of the device into the PHY_TX state.</span></td>
      </tr>
      <tr>
        <td id="L78" class="blob-num js-line-number" data-line-number="78"></td>
        <td id="LC78" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">CMD_PHY_SLEEP</span>        0xBA <span class="pl-c">// Performs a transition of the device into the PHY_SLEEP state.</span></td>
      </tr>
      <tr>
        <td id="L79" class="blob-num js-line-number" data-line-number="79"></td>
        <td id="LC79" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">CMD_CONFIG_DEV</span>       0xBB <span class="pl-c">// Configures the radio parameters based on the BBRAM values.</span></td>
      </tr>
      <tr>
        <td id="L80" class="blob-num js-line-number" data-line-number="80"></td>
        <td id="LC80" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">CMD_GET_RSSI</span>         0xBC <span class="pl-c">// Performs an RSSI measurement.</span></td>
      </tr>
      <tr>
        <td id="L81" class="blob-num js-line-number" data-line-number="81"></td>
        <td id="LC81" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">CMD_BB_CAL</span>           0xBE <span class="pl-c">// Performs a calibration of the IF filter.</span></td>
      </tr>
      <tr>
        <td id="L82" class="blob-num js-line-number" data-line-number="82"></td>
        <td id="LC82" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">CMD_HW_RESET</span>         0xC8 <span class="pl-c">// Performs a full hardware reset. The device enters the PHY_SLEEP state.</span></td>
      </tr>
      <tr>
        <td id="L83" class="blob-num js-line-number" data-line-number="83"></td>
        <td id="LC83" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">CMD_RAM_LOAD_INIT</span>    0xBF <span class="pl-c">// Prepares the program RAM for a firmware module download.</span></td>
      </tr>
      <tr>
        <td id="L84" class="blob-num js-line-number" data-line-number="84"></td>
        <td id="LC84" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">CMD_RAM_LOAD_DONE</span>    0xC7 <span class="pl-c">// Performs a reset of the communications processor after download of a firmware module to program RAM.</span></td>
      </tr>
      <tr>
        <td id="L85" class="blob-num js-line-number" data-line-number="85"></td>
        <td id="LC85" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">CMD_IR_CAL</span>           0xBD <span class="pl-c">// Initiates an image rejection calibration routine.</span></td>
      </tr>
      <tr>
        <td id="L86" class="blob-num js-line-number" data-line-number="86"></td>
        <td id="LC86" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">CMD_AES_ENCRYPT</span>      0xD0 <span class="pl-c">// Performs an AES encryption on the transmit payload data stored in packet RAM.</span></td>
      </tr>
      <tr>
        <td id="L87" class="blob-num js-line-number" data-line-number="87"></td>
        <td id="LC87" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">CMD_AES_DECRYPT</span>      0xD2 <span class="pl-c">// Performs an AES decryption on the received payload data stored in packet RAM.</span></td>
      </tr>
      <tr>
        <td id="L88" class="blob-num js-line-number" data-line-number="88"></td>
        <td id="LC88" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">CMD_AES_DECRYPT_INIT</span> 0xD1 <span class="pl-c">// Initializes the internal variables required for AES decryption.</span></td>
      </tr>
      <tr>
        <td id="L89" class="blob-num js-line-number" data-line-number="89"></td>
        <td id="LC89" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">CMD_RS_ENCODE_INIT</span>   0xD1 <span class="pl-c">// Initializes the internal variables required for the Reed Solomon encoding.</span></td>
      </tr>
      <tr>
        <td id="L90" class="blob-num js-line-number" data-line-number="90"></td>
        <td id="LC90" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">CMD_RS_ENCODE</span>        0xD0 <span class="pl-c">// Calculates and appends the Reed Solomon check bytes to the transmit payload data stored in packet RAM.</span></td>
      </tr>
      <tr>
        <td id="L91" class="blob-num js-line-number" data-line-number="91"></td>
        <td id="LC91" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">CMD_RS_DECODE</span>        0xD2 <span class="pl-c">// Performs a Reed Solomon error correction on the received payload data stored in packet RAM.</span></td>
      </tr>
      <tr>
        <td id="L92" class="blob-num js-line-number" data-line-number="92"></td>
        <td id="LC92" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L93" class="blob-num js-line-number" data-line-number="93"></td>
        <td id="LC93" class="blob-code js-file-line"><span class="pl-c">/* Battery Backup Memory (BBRAM) */</span></td>
      </tr>
      <tr>
        <td id="L94" class="blob-num js-line-number" data-line-number="94"></td>
        <td id="LC94" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_INTERRUPT_MASK_0</span>                  0x100</td>
      </tr>
      <tr>
        <td id="L95" class="blob-num js-line-number" data-line-number="95"></td>
        <td id="LC95" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_INTERRUPT_MASK_1</span>                  0x101</td>
      </tr>
      <tr>
        <td id="L96" class="blob-num js-line-number" data-line-number="96"></td>
        <td id="LC96" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_NUMBER_OF_WAKEUPS_0</span>               0x102</td>
      </tr>
      <tr>
        <td id="L97" class="blob-num js-line-number" data-line-number="97"></td>
        <td id="LC97" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_NUMBER_OF_WAKEUPS_1</span>               0x103</td>
      </tr>
      <tr>
        <td id="L98" class="blob-num js-line-number" data-line-number="98"></td>
        <td id="LC98" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_NUMBER_OF_WAKEUPS_IRQ_THRESHOLD_0</span> 0x104</td>
      </tr>
      <tr>
        <td id="L99" class="blob-num js-line-number" data-line-number="99"></td>
        <td id="LC99" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_NUMBER_OF_WAKEUPS_IRQ_THRESHOLD_1</span> 0x105</td>
      </tr>
      <tr>
        <td id="L100" class="blob-num js-line-number" data-line-number="100"></td>
        <td id="LC100" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_RX_DWELL_TIME</span>                     0x106</td>
      </tr>
      <tr>
        <td id="L101" class="blob-num js-line-number" data-line-number="101"></td>
        <td id="LC101" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_PARMTIME_DIVIDER</span>                  0x107</td>
      </tr>
      <tr>
        <td id="L102" class="blob-num js-line-number" data-line-number="102"></td>
        <td id="LC102" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_SWM_RSSI_THRESH</span>                   0x108</td>
      </tr>
      <tr>
        <td id="L103" class="blob-num js-line-number" data-line-number="103"></td>
        <td id="LC103" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_CHANNEL_FREQ_0</span>                    0x109</td>
      </tr>
      <tr>
        <td id="L104" class="blob-num js-line-number" data-line-number="104"></td>
        <td id="LC104" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_CHANNEL_FREQ_1</span>                    0x10A</td>
      </tr>
      <tr>
        <td id="L105" class="blob-num js-line-number" data-line-number="105"></td>
        <td id="LC105" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_CHANNEL_FREQ_2</span>                    0x10B</td>
      </tr>
      <tr>
        <td id="L106" class="blob-num js-line-number" data-line-number="106"></td>
        <td id="LC106" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_RADIO_CFG_0</span>                       0x10C</td>
      </tr>
      <tr>
        <td id="L107" class="blob-num js-line-number" data-line-number="107"></td>
        <td id="LC107" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_RADIO_CFG_1</span>                       0x10D</td>
      </tr>
      <tr>
        <td id="L108" class="blob-num js-line-number" data-line-number="108"></td>
        <td id="LC108" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_RADIO_CFG_2</span>                       0x10E</td>
      </tr>
      <tr>
        <td id="L109" class="blob-num js-line-number" data-line-number="109"></td>
        <td id="LC109" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_RADIO_CFG_3</span>                       0x10F</td>
      </tr>
      <tr>
        <td id="L110" class="blob-num js-line-number" data-line-number="110"></td>
        <td id="LC110" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_RADIO_CFG_4</span>                       0x110</td>
      </tr>
      <tr>
        <td id="L111" class="blob-num js-line-number" data-line-number="111"></td>
        <td id="LC111" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_RADIO_CFG_5</span>                       0x111</td>
      </tr>
      <tr>
        <td id="L112" class="blob-num js-line-number" data-line-number="112"></td>
        <td id="LC112" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_RADIO_CFG_6</span>                       0x112</td>
      </tr>
      <tr>
        <td id="L113" class="blob-num js-line-number" data-line-number="113"></td>
        <td id="LC113" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_RADIO_CFG_7</span>                       0x113</td>
      </tr>
      <tr>
        <td id="L114" class="blob-num js-line-number" data-line-number="114"></td>
        <td id="LC114" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_RADIO_CFG_8</span>                       0x114</td>
      </tr>
      <tr>
        <td id="L115" class="blob-num js-line-number" data-line-number="115"></td>
        <td id="LC115" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_RADIO_CFG_9</span>                       0x115</td>
      </tr>
      <tr>
        <td id="L116" class="blob-num js-line-number" data-line-number="116"></td>
        <td id="LC116" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_RADIO_CFG_10</span>                      0x116</td>
      </tr>
      <tr>
        <td id="L117" class="blob-num js-line-number" data-line-number="117"></td>
        <td id="LC117" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_RADIO_CFG_11</span>                      0x117</td>
      </tr>
      <tr>
        <td id="L118" class="blob-num js-line-number" data-line-number="118"></td>
        <td id="LC118" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_IMAGE_REJECT_CAL_PHASE</span>            0x118</td>
      </tr>
      <tr>
        <td id="L119" class="blob-num js-line-number" data-line-number="119"></td>
        <td id="LC119" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_IMAGE_REJECT_CAL_AMPLITUDE</span>        0x119</td>
      </tr>
      <tr>
        <td id="L120" class="blob-num js-line-number" data-line-number="120"></td>
        <td id="LC120" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_MODE_CONTROL</span>                      0x11A</td>
      </tr>
      <tr>
        <td id="L121" class="blob-num js-line-number" data-line-number="121"></td>
        <td id="LC121" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_PREAMBLE_MATCH</span>                    0x11B</td>
      </tr>
      <tr>
        <td id="L122" class="blob-num js-line-number" data-line-number="122"></td>
        <td id="LC122" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_SYMBOL_MODE</span>                       0x11C</td>
      </tr>
      <tr>
        <td id="L123" class="blob-num js-line-number" data-line-number="123"></td>
        <td id="LC123" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_PREAMBLE_LEN</span>                      0x11D</td>
      </tr>
      <tr>
        <td id="L124" class="blob-num js-line-number" data-line-number="124"></td>
        <td id="LC124" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_CRC_POLY_0</span>                        0x11E</td>
      </tr>
      <tr>
        <td id="L125" class="blob-num js-line-number" data-line-number="125"></td>
        <td id="LC125" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_CRC_POLY_1</span>                        0x11F</td>
      </tr>
      <tr>
        <td id="L126" class="blob-num js-line-number" data-line-number="126"></td>
        <td id="LC126" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_SYNC_CONTROL</span>                      0x120</td>
      </tr>
      <tr>
        <td id="L127" class="blob-num js-line-number" data-line-number="127"></td>
        <td id="LC127" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_SYNC_BYTE_0</span>                       0x121</td>
      </tr>
      <tr>
        <td id="L128" class="blob-num js-line-number" data-line-number="128"></td>
        <td id="LC128" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_SYNC_BYTE_1</span>                       0x122</td>
      </tr>
      <tr>
        <td id="L129" class="blob-num js-line-number" data-line-number="129"></td>
        <td id="LC129" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_SYNC_BYTE_2</span>                       0x123</td>
      </tr>
      <tr>
        <td id="L130" class="blob-num js-line-number" data-line-number="130"></td>
        <td id="LC130" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_TX_BASE_ADR</span>                       0x124</td>
      </tr>
      <tr>
        <td id="L131" class="blob-num js-line-number" data-line-number="131"></td>
        <td id="LC131" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_RX_BASE_ADR</span>                       0x125</td>
      </tr>
      <tr>
        <td id="L132" class="blob-num js-line-number" data-line-number="132"></td>
        <td id="LC132" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_PACKET_LENGTH_CONTROL</span>             0x126</td>
      </tr>
      <tr>
        <td id="L133" class="blob-num js-line-number" data-line-number="133"></td>
        <td id="LC133" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_PACKET_LENGTH_MAX</span>                 0x127</td>
      </tr>
      <tr>
        <td id="L134" class="blob-num js-line-number" data-line-number="134"></td>
        <td id="LC134" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_STATIC_REG_FIX</span>                    0x128</td>
      </tr>
      <tr>
        <td id="L135" class="blob-num js-line-number" data-line-number="135"></td>
        <td id="LC135" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_ADDRESS_MATCH_OFFSET</span>              0x129</td>
      </tr>
      <tr>
        <td id="L136" class="blob-num js-line-number" data-line-number="136"></td>
        <td id="LC136" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_ADDRESS_LENGTH</span>                    0x12A</td>
      </tr>
      <tr>
        <td id="L137" class="blob-num js-line-number" data-line-number="137"></td>
        <td id="LC137" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_ADDRESS_FILTERING_0</span>               0x12B</td>
      </tr>
      <tr>
        <td id="L138" class="blob-num js-line-number" data-line-number="138"></td>
        <td id="LC138" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_ADDRESS_FILTERING_1</span>               0x12C</td>
      </tr>
      <tr>
        <td id="L139" class="blob-num js-line-number" data-line-number="139"></td>
        <td id="LC139" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_ADDRESS_FILTERING_2</span>               0x12D</td>
      </tr>
      <tr>
        <td id="L140" class="blob-num js-line-number" data-line-number="140"></td>
        <td id="LC140" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_ADDRESS_FILTERING_3</span>               0x12E</td>
      </tr>
      <tr>
        <td id="L141" class="blob-num js-line-number" data-line-number="141"></td>
        <td id="LC141" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_ADDRESS_FILTERING_4</span>               0x12F</td>
      </tr>
      <tr>
        <td id="L142" class="blob-num js-line-number" data-line-number="142"></td>
        <td id="LC142" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_ADDRESS_FILTERING_5</span>               0x130</td>
      </tr>
      <tr>
        <td id="L143" class="blob-num js-line-number" data-line-number="143"></td>
        <td id="LC143" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_ADDRESS_FILTERING_6</span>               0x131</td>
      </tr>
      <tr>
        <td id="L144" class="blob-num js-line-number" data-line-number="144"></td>
        <td id="LC144" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_ADDRESS_FILTERING_7</span>               0x132</td>
      </tr>
      <tr>
        <td id="L145" class="blob-num js-line-number" data-line-number="145"></td>
        <td id="LC145" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_ADDRESS_FILTERING_8</span>               0x133</td>
      </tr>
      <tr>
        <td id="L146" class="blob-num js-line-number" data-line-number="146"></td>
        <td id="LC146" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_ADDRESS_FILTERING_9</span>               0x134</td>
      </tr>
      <tr>
        <td id="L147" class="blob-num js-line-number" data-line-number="147"></td>
        <td id="LC147" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_ADDRESS_FILTERING_10</span>              0x135</td>
      </tr>
      <tr>
        <td id="L148" class="blob-num js-line-number" data-line-number="148"></td>
        <td id="LC148" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_ADDRESS_FILTERING_11</span>              0x136</td>
      </tr>
      <tr>
        <td id="L149" class="blob-num js-line-number" data-line-number="149"></td>
        <td id="LC149" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_ADDRESS_FILTERING_12</span>              0x137</td>
      </tr>
      <tr>
        <td id="L150" class="blob-num js-line-number" data-line-number="150"></td>
        <td id="LC150" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_RSSI_WAIT_TIME</span>                    0x138</td>
      </tr>
      <tr>
        <td id="L151" class="blob-num js-line-number" data-line-number="151"></td>
        <td id="LC151" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_TESTMODES</span>                         0x139</td>
      </tr>
      <tr>
        <td id="L152" class="blob-num js-line-number" data-line-number="152"></td>
        <td id="LC152" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_TRANSITION_CLOCK_DIV</span>              0x13A</td>
      </tr>
      <tr>
        <td id="L153" class="blob-num js-line-number" data-line-number="153"></td>
        <td id="LC153" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_RESERVED_0</span>                        0x13B</td>
      </tr>
      <tr>
        <td id="L154" class="blob-num js-line-number" data-line-number="154"></td>
        <td id="LC154" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_RESERVED_1</span>                        0x13C</td>
      </tr>
      <tr>
        <td id="L155" class="blob-num js-line-number" data-line-number="155"></td>
        <td id="LC155" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_RESERVED_2</span>                        0x13D</td>
      </tr>
      <tr>
        <td id="L156" class="blob-num js-line-number" data-line-number="156"></td>
        <td id="LC156" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_RX_SYNTH_LOCK_TIME</span>                0x13E</td>
      </tr>
      <tr>
        <td id="L157" class="blob-num js-line-number" data-line-number="157"></td>
        <td id="LC157" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_REG_TX_SYNTH_LOCK_TIME</span>                0x13F</td>
      </tr>
      <tr>
        <td id="L158" class="blob-num js-line-number" data-line-number="158"></td>
        <td id="LC158" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L159" class="blob-num js-line-number" data-line-number="159"></td>
        <td id="LC159" class="blob-code js-file-line"><span class="pl-c">/* BBRAM_REG_INTERRUPT_MASK_0 - 0x100 */</span></td>
      </tr>
      <tr>
        <td id="L160" class="blob-num js-line-number" data-line-number="160"></td>
        <td id="LC160" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_INTERRUPT_MASK_0_INTERRUPT_NUM_WAKEUPS</span>     (0x1 &lt;&lt; <span class="pl-c1">7</span>)</td>
      </tr>
      <tr>
        <td id="L161" class="blob-num js-line-number" data-line-number="161"></td>
        <td id="LC161" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_INTERRUPT_MASK_0_INTERRUPT_SWM_RSSI_DET</span>    (0x1 &lt;&lt; <span class="pl-c1">6</span>)</td>
      </tr>
      <tr>
        <td id="L162" class="blob-num js-line-number" data-line-number="162"></td>
        <td id="LC162" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_INTERRUPT_MASK_0_INTERRUPT_AES_DONE</span>        (0x1 &lt;&lt; <span class="pl-c1">5</span>)</td>
      </tr>
      <tr>
        <td id="L163" class="blob-num js-line-number" data-line-number="163"></td>
        <td id="LC163" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_INTERRUPT_MASK_0_INTERRUPT_TX_EOF</span>          (0x1 &lt;&lt; <span class="pl-c1">4</span>)</td>
      </tr>
      <tr>
        <td id="L164" class="blob-num js-line-number" data-line-number="164"></td>
        <td id="LC164" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_INTERRUPT_MASK_0_INTERRUPT_ADDRESS_MATCH</span>   (0x1 &lt;&lt; <span class="pl-c1">3</span>)</td>
      </tr>
      <tr>
        <td id="L165" class="blob-num js-line-number" data-line-number="165"></td>
        <td id="LC165" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_INTERRUPT_MASK_0_INTERRUPT_CRC_CORRECT</span>     (0x1 &lt;&lt; <span class="pl-c1">2</span>)</td>
      </tr>
      <tr>
        <td id="L166" class="blob-num js-line-number" data-line-number="166"></td>
        <td id="LC166" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_INTERRUPT_MASK_0_INTERRUPT_SYNC_DETECT</span>     (0x1 &lt;&lt; <span class="pl-c1">1</span>)</td>
      </tr>
      <tr>
        <td id="L167" class="blob-num js-line-number" data-line-number="167"></td>
        <td id="LC167" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_INTERRUPT_MASK_0_INTERRUPT_PREMABLE_DETECT</span> (0x1 &lt;&lt; <span class="pl-c1">0</span>)</td>
      </tr>
      <tr>
        <td id="L168" class="blob-num js-line-number" data-line-number="168"></td>
        <td id="LC168" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L169" class="blob-num js-line-number" data-line-number="169"></td>
        <td id="LC169" class="blob-code js-file-line"><span class="pl-c">/* BBRAM_REG_INTERRUPT_MASK_1 - 0x101*/</span></td>
      </tr>
      <tr>
        <td id="L170" class="blob-num js-line-number" data-line-number="170"></td>
        <td id="LC170" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_INTERRUPT_MASK_1_BATTERY_ALARM</span> (0x1 &lt;&lt; <span class="pl-c1">7</span>)</td>
      </tr>
      <tr>
        <td id="L171" class="blob-num js-line-number" data-line-number="171"></td>
        <td id="LC171" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_INTERRUPT_MASK_1_CMD_READY</span>     (0x1 &lt;&lt; <span class="pl-c1">6</span>)</td>
      </tr>
      <tr>
        <td id="L172" class="blob-num js-line-number" data-line-number="172"></td>
        <td id="LC172" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_INTERRUPT_MASK_1_WUC_TIMEOUT</span>   (0x1 &lt;&lt; <span class="pl-c1">4</span>)</td>
      </tr>
      <tr>
        <td id="L173" class="blob-num js-line-number" data-line-number="173"></td>
        <td id="LC173" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_INTERRUPT_MASK_1_SPI_READY</span>     (0x1 &lt;&lt; <span class="pl-c1">1</span>)</td>
      </tr>
      <tr>
        <td id="L174" class="blob-num js-line-number" data-line-number="174"></td>
        <td id="LC174" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_INTERRUPT_MASK_1_CMD_FINISHED</span>  (0x1 &lt;&lt; <span class="pl-c1">0</span>)</td>
      </tr>
      <tr>
        <td id="L175" class="blob-num js-line-number" data-line-number="175"></td>
        <td id="LC175" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L176" class="blob-num js-line-number" data-line-number="176"></td>
        <td id="LC176" class="blob-code js-file-line"><span class="pl-c">/* BBRAM_REG_RADIO_CFG_0 - 0x10C */</span></td>
      </tr>
      <tr>
        <td id="L177" class="blob-num js-line-number" data-line-number="177"></td>
        <td id="LC177" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_RADIO_CFG_0_DATA_RATE_7_0</span>(<span class="pl-v">x</span>) ((x &amp; 0xFF) &lt;&lt; <span class="pl-c1">0</span>)</td>
      </tr>
      <tr>
        <td id="L178" class="blob-num js-line-number" data-line-number="178"></td>
        <td id="LC178" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L179" class="blob-num js-line-number" data-line-number="179"></td>
        <td id="LC179" class="blob-code js-file-line"><span class="pl-c">/* BBRAM_REG_RADIO_CFG_1 - 0x10D */</span></td>
      </tr>
      <tr>
        <td id="L180" class="blob-num js-line-number" data-line-number="180"></td>
        <td id="LC180" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_RADIO_CFG_1_FREQ_DEVIATION_11_8</span>(<span class="pl-v">x</span>) ((x &amp; <span class="pl-c1">0xF</span>) &lt;&lt; <span class="pl-c1">4</span>)</td>
      </tr>
      <tr>
        <td id="L181" class="blob-num js-line-number" data-line-number="181"></td>
        <td id="LC181" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_RADIO_CFG_1_DATA_RATE_11_8</span>(<span class="pl-v">x</span>)      ((x &amp; <span class="pl-c1">0xF</span>) &lt;&lt; <span class="pl-c1">0</span>)</td>
      </tr>
      <tr>
        <td id="L182" class="blob-num js-line-number" data-line-number="182"></td>
        <td id="LC182" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L183" class="blob-num js-line-number" data-line-number="183"></td>
        <td id="LC183" class="blob-code js-file-line"><span class="pl-c">/* BBRAM_REG_RADIO_CFG_2 - 0x10E */</span></td>
      </tr>
      <tr>
        <td id="L184" class="blob-num js-line-number" data-line-number="184"></td>
        <td id="LC184" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_RADIO_CFG_2_FREQ_DEVIATION_7_0</span>(<span class="pl-v">x</span>) ((x &amp; 0xFF) &lt;&lt; <span class="pl-c1">0</span>)</td>
      </tr>
      <tr>
        <td id="L185" class="blob-num js-line-number" data-line-number="185"></td>
        <td id="LC185" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L186" class="blob-num js-line-number" data-line-number="186"></td>
        <td id="LC186" class="blob-code js-file-line"><span class="pl-c">/* BBRAM_REG_RADIO_CFG_6 - 0x112 */</span></td>
      </tr>
      <tr>
        <td id="L187" class="blob-num js-line-number" data-line-number="187"></td>
        <td id="LC187" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_RADIO_CFG_6_SYNTH_LUT_CONFIG_0</span>(<span class="pl-v">x</span>) ((x &amp; 0x3F) &lt;&lt; <span class="pl-c1">2</span>)</td>
      </tr>
      <tr>
        <td id="L188" class="blob-num js-line-number" data-line-number="188"></td>
        <td id="LC188" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_RADIO_CFG_6_DISCRIM_PHASE</span>(<span class="pl-v">x</span>)      ((x &amp; 0x3) &lt;&lt; <span class="pl-c1">0</span>)</td>
      </tr>
      <tr>
        <td id="L189" class="blob-num js-line-number" data-line-number="189"></td>
        <td id="LC189" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L190" class="blob-num js-line-number" data-line-number="190"></td>
        <td id="LC190" class="blob-code js-file-line"><span class="pl-c">/* BBRAM_REG_RADIO_CFG_7 - 0x113 */</span></td>
      </tr>
      <tr>
        <td id="L191" class="blob-num js-line-number" data-line-number="191"></td>
        <td id="LC191" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_RADIO_CFG_7_AGC_LOCK_MODE</span>(<span class="pl-v">x</span>)      ((x &amp; 0x3) &lt;&lt; <span class="pl-c1">6</span>)</td>
      </tr>
      <tr>
        <td id="L192" class="blob-num js-line-number" data-line-number="192"></td>
        <td id="LC192" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_RADIO_CFG_7_SYNTH_LUT_CONTROL</span>(<span class="pl-v">x</span>)  ((x &amp; 0x3) &lt;&lt; <span class="pl-c1">4</span>)</td>
      </tr>
      <tr>
        <td id="L193" class="blob-num js-line-number" data-line-number="193"></td>
        <td id="LC193" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_RADIO_CFG_7_SYNTH_LUT_CONFIG_1</span>(<span class="pl-v">x</span>) ((x &amp; <span class="pl-c1">0xF</span>) &lt;&lt; <span class="pl-c1">0</span>)</td>
      </tr>
      <tr>
        <td id="L194" class="blob-num js-line-number" data-line-number="194"></td>
        <td id="LC194" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L195" class="blob-num js-line-number" data-line-number="195"></td>
        <td id="LC195" class="blob-code js-file-line"><span class="pl-c">/* BBRAM_REG_RADIO_CFG_8 - 0x114 */</span></td>
      </tr>
      <tr>
        <td id="L196" class="blob-num js-line-number" data-line-number="196"></td>
        <td id="LC196" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_RADIO_CFG_8_PA_SINGLE_DIFF_SEL</span> (0x1 &lt;&lt; <span class="pl-c1">7</span>)</td>
      </tr>
      <tr>
        <td id="L197" class="blob-num js-line-number" data-line-number="197"></td>
        <td id="LC197" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_RADIO_CFG_8_PA_LEVEL</span>(<span class="pl-v">x</span>)        ((x &amp; <span class="pl-c1">0xF</span>) &lt;&lt; <span class="pl-c1">3</span>)</td>
      </tr>
      <tr>
        <td id="L198" class="blob-num js-line-number" data-line-number="198"></td>
        <td id="LC198" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_RADIO_CFG_8_PA_RAMP</span>(<span class="pl-v">x</span>)         ((x &amp; 0x7) &lt;&lt; <span class="pl-c1">0</span>)</td>
      </tr>
      <tr>
        <td id="L199" class="blob-num js-line-number" data-line-number="199"></td>
        <td id="LC199" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L200" class="blob-num js-line-number" data-line-number="200"></td>
        <td id="LC200" class="blob-code js-file-line"><span class="pl-c">/* BBRAM_REG_RADIO_CFG_9 - 0x115 */</span></td>
      </tr>
      <tr>
        <td id="L201" class="blob-num js-line-number" data-line-number="201"></td>
        <td id="LC201" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_RADIO_CFG_9_IFBW</span>(<span class="pl-v">x</span>)         ((x &amp; 0x3) &lt;&lt; <span class="pl-c1">6</span>)</td>
      </tr>
      <tr>
        <td id="L202" class="blob-num js-line-number" data-line-number="202"></td>
        <td id="LC202" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_RADIO_CFG_9_MOD_SCHEME</span>(<span class="pl-v">x</span>)   ((x &amp; 0x7) &lt;&lt; <span class="pl-c1">3</span>)</td>
      </tr>
      <tr>
        <td id="L203" class="blob-num js-line-number" data-line-number="203"></td>
        <td id="LC203" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_RADIO_CFG_9_DEMOD_SCHEME</span>(<span class="pl-v">x</span>) ((x &amp; 0x7) &lt;&lt; <span class="pl-c1">0</span>)</td>
      </tr>
      <tr>
        <td id="L204" class="blob-num js-line-number" data-line-number="204"></td>
        <td id="LC204" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L205" class="blob-num js-line-number" data-line-number="205"></td>
        <td id="LC205" class="blob-code js-file-line"><span class="pl-c">/* BBRAM_REG_RADIO_CFG_10 - 0x116 */</span></td>
      </tr>
      <tr>
        <td id="L206" class="blob-num js-line-number" data-line-number="206"></td>
        <td id="LC206" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_RADIO_CFG_10_AFC_POLARITY</span>     (0x0 &lt;&lt; <span class="pl-c1">4</span>)</td>
      </tr>
      <tr>
        <td id="L207" class="blob-num js-line-number" data-line-number="207"></td>
        <td id="LC207" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_RADIO_CFG_10_AFC_SCHEME</span>(<span class="pl-v">x</span>)    ((x &amp; 0x3) &lt;&lt; <span class="pl-c1">2</span>)</td>
      </tr>
      <tr>
        <td id="L208" class="blob-num js-line-number" data-line-number="208"></td>
        <td id="LC208" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_RADIO_CFG_10_AFC_LOCK_MODE</span>(<span class="pl-v">x</span>) ((x &amp; 0x3) &lt;&lt; <span class="pl-c1">0</span>)</td>
      </tr>
      <tr>
        <td id="L209" class="blob-num js-line-number" data-line-number="209"></td>
        <td id="LC209" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L210" class="blob-num js-line-number" data-line-number="210"></td>
        <td id="LC210" class="blob-code js-file-line"><span class="pl-c">/* BBRAM_REG_RADIO_CFG_11 - 0x117 */</span></td>
      </tr>
      <tr>
        <td id="L211" class="blob-num js-line-number" data-line-number="211"></td>
        <td id="LC211" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_RADIO_CFG_11_AFC_KP</span>(<span class="pl-v">x</span>) ((x &amp; <span class="pl-c1">0xF</span>) &lt;&lt; <span class="pl-c1">4</span>)</td>
      </tr>
      <tr>
        <td id="L212" class="blob-num js-line-number" data-line-number="212"></td>
        <td id="LC212" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_RADIO_CFG_11_AFC_KI</span>(<span class="pl-v">x</span>) ((x &amp; <span class="pl-c1">0xF</span>) &lt;&lt; <span class="pl-c1">0</span>)</td>
      </tr>
      <tr>
        <td id="L213" class="blob-num js-line-number" data-line-number="213"></td>
        <td id="LC213" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L214" class="blob-num js-line-number" data-line-number="214"></td>
        <td id="LC214" class="blob-code js-file-line"><span class="pl-c">/* BBRAM_REG_MODE_CONTROL - 0x11A */</span></td>
      </tr>
      <tr>
        <td id="L215" class="blob-num js-line-number" data-line-number="215"></td>
        <td id="LC215" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_MODE_CONTROL_SWM_EN</span>                        (0x1 &lt;&lt; <span class="pl-c1">7</span>)</td>
      </tr>
      <tr>
        <td id="L216" class="blob-num js-line-number" data-line-number="216"></td>
        <td id="LC216" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_MODE_CONTROL_BB_CAL</span>                        (0x1 &lt;&lt; <span class="pl-c1">6</span>)</td>
      </tr>
      <tr>
        <td id="L217" class="blob-num js-line-number" data-line-number="217"></td>
        <td id="LC217" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_MODE_CONTROL_SWM_RSSI_QUAL</span>                 (0x1 &lt;&lt; <span class="pl-c1">5</span>)</td>
      </tr>
      <tr>
        <td id="L218" class="blob-num js-line-number" data-line-number="218"></td>
        <td id="LC218" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_MODE_CONTROL_TX_TO_RX_AUTO_TURNAROUND</span>      (0x1 &lt;&lt; <span class="pl-c1">4</span>)</td>
      </tr>
      <tr>
        <td id="L219" class="blob-num js-line-number" data-line-number="219"></td>
        <td id="LC219" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_MODE_CONTROL_RX_TO_TX_AUTO_TURNAROUND</span>      (0x1 &lt;&lt; <span class="pl-c1">3</span>)</td>
      </tr>
      <tr>
        <td id="L220" class="blob-num js-line-number" data-line-number="220"></td>
        <td id="LC220" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_MODE_CONTROL_CUSTOM_TRX_SYNTH_LOCK_TIME_EN</span> (0x1 &lt;&lt; <span class="pl-c1">2</span>)</td>
      </tr>
      <tr>
        <td id="L221" class="blob-num js-line-number" data-line-number="221"></td>
        <td id="LC221" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_MODE_CONTROL_EXT_LNA_EN</span>                    (0x1 &lt;&lt; <span class="pl-c1">1</span>)</td>
      </tr>
      <tr>
        <td id="L222" class="blob-num js-line-number" data-line-number="222"></td>
        <td id="LC222" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_MODE_CONTROL_EXT_PA_EN</span>                     (0x1 &lt;&lt; <span class="pl-c1">0</span>)</td>
      </tr>
      <tr>
        <td id="L223" class="blob-num js-line-number" data-line-number="223"></td>
        <td id="LC223" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L224" class="blob-num js-line-number" data-line-number="224"></td>
        <td id="LC224" class="blob-code js-file-line"><span class="pl-c">/* BBRAM_REG_SYMBOL_MODE - 0x11C */</span></td>
      </tr>
      <tr>
        <td id="L225" class="blob-num js-line-number" data-line-number="225"></td>
        <td id="LC225" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_SYMBOL_MODE_MANCHESTER_ENC</span>   (0x1 &lt;&lt; <span class="pl-c1">6</span>)</td>
      </tr>
      <tr>
        <td id="L226" class="blob-num js-line-number" data-line-number="226"></td>
        <td id="LC226" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_SYMBOL_MODE_PROG_CRC_EN</span>      (0x1 &lt;&lt; <span class="pl-c1">5</span>)</td>
      </tr>
      <tr>
        <td id="L227" class="blob-num js-line-number" data-line-number="227"></td>
        <td id="LC227" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_SYMBOL_MODE_EIGHT_TEN_ENC</span>    (0x1 &lt;&lt; <span class="pl-c1">4</span>)</td>
      </tr>
      <tr>
        <td id="L228" class="blob-num js-line-number" data-line-number="228"></td>
        <td id="LC228" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_SYMBOL_MODE_DATA_WHITENING</span>   (0x1 &lt;&lt; <span class="pl-c1">3</span>)</td>
      </tr>
      <tr>
        <td id="L229" class="blob-num js-line-number" data-line-number="229"></td>
        <td id="LC229" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_SYMBOL_MODE_SYMBOL_LENGTH</span>(<span class="pl-v">x</span>) ((x &amp; 0x7) &lt;&lt; <span class="pl-c1">0</span>)</td>
      </tr>
      <tr>
        <td id="L230" class="blob-num js-line-number" data-line-number="230"></td>
        <td id="LC230" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L231" class="blob-num js-line-number" data-line-number="231"></td>
        <td id="LC231" class="blob-code js-file-line"><span class="pl-c">/* BBRAM_REG_SYNC_CONTROL - 0x120 */</span></td>
      </tr>
      <tr>
        <td id="L232" class="blob-num js-line-number" data-line-number="232"></td>
        <td id="LC232" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_SYNC_CONTROL_SYNC_ERROR_TOL</span>(<span class="pl-v">x</span>)   ((x &amp; 0x3) &lt;&lt; <span class="pl-c1">6</span>)</td>
      </tr>
      <tr>
        <td id="L233" class="blob-num js-line-number" data-line-number="233"></td>
        <td id="LC233" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_SYNC_CONTROL_SYNC_WORD_LENGTH</span>(<span class="pl-v">x</span>) ((x &amp; 0x1F) &lt;&lt; <span class="pl-c1">0</span>)</td>
      </tr>
      <tr>
        <td id="L234" class="blob-num js-line-number" data-line-number="234"></td>
        <td id="LC234" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L235" class="blob-num js-line-number" data-line-number="235"></td>
        <td id="LC235" class="blob-code js-file-line"><span class="pl-c">/* BBRAM_REG_PACKET_LENGTH_CONTROL - 0x126 */</span></td>
      </tr>
      <tr>
        <td id="L236" class="blob-num js-line-number" data-line-number="236"></td>
        <td id="LC236" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_PACKET_LENGTH_CONTROL_DATA_BYTE</span>        (0x1 &lt;&lt; <span class="pl-c1">7</span>)</td>
      </tr>
      <tr>
        <td id="L237" class="blob-num js-line-number" data-line-number="237"></td>
        <td id="LC237" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_PACKET_LENGTH_CONTROL_PACKET_LEN</span>       (0x1 &lt;&lt; <span class="pl-c1">6</span>)</td>
      </tr>
      <tr>
        <td id="L238" class="blob-num js-line-number" data-line-number="238"></td>
        <td id="LC238" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_PACKET_LENGTH_CONTROL_CRC_EN</span>           (0x1 &lt;&lt; <span class="pl-c1">5</span>)</td>
      </tr>
      <tr>
        <td id="L239" class="blob-num js-line-number" data-line-number="239"></td>
        <td id="LC239" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_PACKET_LENGTH_CONTROL_DATA_MODE</span>(<span class="pl-v">x</span>)     ((x &amp; 0x3) &lt;&lt; <span class="pl-c1">3</span>)</td>
      </tr>
      <tr>
        <td id="L240" class="blob-num js-line-number" data-line-number="240"></td>
        <td id="LC240" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_PACKET_LENGTH_CONTROL_LENGTH_OFFSET</span>(<span class="pl-v">x</span>) ((x &amp; 0x7) &lt;&lt; <span class="pl-c1">0</span>)</td>
      </tr>
      <tr>
        <td id="L241" class="blob-num js-line-number" data-line-number="241"></td>
        <td id="LC241" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L242" class="blob-num js-line-number" data-line-number="242"></td>
        <td id="LC242" class="blob-code js-file-line"><span class="pl-c">/* BBRAM_REG_TESTMODES - 0x139 */</span></td>
      </tr>
      <tr>
        <td id="L243" class="blob-num js-line-number" data-line-number="243"></td>
        <td id="LC243" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_TESTMODES_EXT_PA_LNA_ATB_CONFIG</span> (0x1 &lt;&lt; <span class="pl-c1">7</span>)</td>
      </tr>
      <tr>
        <td id="L244" class="blob-num js-line-number" data-line-number="244"></td>
        <td id="LC244" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_TESTMODES_PER_IRQ_SELF_CLEAR</span>    (0x1 &lt;&lt; <span class="pl-c1">3</span>)</td>
      </tr>
      <tr>
        <td id="L245" class="blob-num js-line-number" data-line-number="245"></td>
        <td id="LC245" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_TESTMODES_PER_ENABLE</span>            (0x1 &lt;&lt; <span class="pl-c1">2</span>)</td>
      </tr>
      <tr>
        <td id="L246" class="blob-num js-line-number" data-line-number="246"></td>
        <td id="LC246" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_TESTMODES_CONTINUOUS_TX</span>         (0x1 &lt;&lt; <span class="pl-c1">1</span>)</td>
      </tr>
      <tr>
        <td id="L247" class="blob-num js-line-number" data-line-number="247"></td>
        <td id="LC247" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">BBRAM_TESTMODES_CONTINUOUS_RX</span>         (0x1 &lt;&lt; <span class="pl-c1">0</span>)</td>
      </tr>
      <tr>
        <td id="L248" class="blob-num js-line-number" data-line-number="248"></td>
        <td id="LC248" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L249" class="blob-num js-line-number" data-line-number="249"></td>
        <td id="LC249" class="blob-code js-file-line"><span class="pl-c">/* Modem Configuration Memory (MCR) */</span></td>
      </tr>
      <tr>
        <td id="L250" class="blob-num js-line-number" data-line-number="250"></td>
        <td id="LC250" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_PA_LEVEL_MCR</span>                      0x307</td>
      </tr>
      <tr>
        <td id="L251" class="blob-num js-line-number" data-line-number="251"></td>
        <td id="LC251" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_WUC_CONFIG_HIGH</span>                   0x30C</td>
      </tr>
      <tr>
        <td id="L252" class="blob-num js-line-number" data-line-number="252"></td>
        <td id="LC252" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_WUC_CONFIG_LOW</span>                    0x30D</td>
      </tr>
      <tr>
        <td id="L253" class="blob-num js-line-number" data-line-number="253"></td>
        <td id="LC253" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_WUC_VALUE_HIGH</span>                    0x30E</td>
      </tr>
      <tr>
        <td id="L254" class="blob-num js-line-number" data-line-number="254"></td>
        <td id="LC254" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_WUC_VALUE_LOW</span>                     0x30F</td>
      </tr>
      <tr>
        <td id="L255" class="blob-num js-line-number" data-line-number="255"></td>
        <td id="LC255" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_WUC_FLAG_RESET</span>                    0x310</td>
      </tr>
      <tr>
        <td id="L256" class="blob-num js-line-number" data-line-number="256"></td>
        <td id="LC256" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_WUC_STATUS</span>                        0x311</td>
      </tr>
      <tr>
        <td id="L257" class="blob-num js-line-number" data-line-number="257"></td>
        <td id="LC257" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_RSSI_READBACK</span>                     0x312</td>
      </tr>
      <tr>
        <td id="L258" class="blob-num js-line-number" data-line-number="258"></td>
        <td id="LC258" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_MAX_AFC_RANGE</span>                     0x315</td>
      </tr>
      <tr>
        <td id="L259" class="blob-num js-line-number" data-line-number="259"></td>
        <td id="LC259" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_IMAGE_REJECT_CAL_CONFIG</span>           0x319</td>
      </tr>
      <tr>
        <td id="L260" class="blob-num js-line-number" data-line-number="260"></td>
        <td id="LC260" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_CHIP_SHUTDOWN</span>                     0x322</td>
      </tr>
      <tr>
        <td id="L261" class="blob-num js-line-number" data-line-number="261"></td>
        <td id="LC261" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_POWERDOWN_RX</span>                      0x324</td>
      </tr>
      <tr>
        <td id="L262" class="blob-num js-line-number" data-line-number="262"></td>
        <td id="LC262" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_POWERDOWN_AUX</span>                     0x325</td>
      </tr>
      <tr>
        <td id="L263" class="blob-num js-line-number" data-line-number="263"></td>
        <td id="LC263" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_ADC_READBACK_HIGH</span>                 0x327</td>
      </tr>
      <tr>
        <td id="L264" class="blob-num js-line-number" data-line-number="264"></td>
        <td id="LC264" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_ADC_READBACK_LOW</span>                  0x328</td>
      </tr>
      <tr>
        <td id="L265" class="blob-num js-line-number" data-line-number="265"></td>
        <td id="LC265" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_BATTERY_MONITOR_THRESHOLD_VOLTAGE</span> 0x32D</td>
      </tr>
      <tr>
        <td id="L266" class="blob-num js-line-number" data-line-number="266"></td>
        <td id="LC266" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_EXT_UC_CLK_DIVIDE</span>                 0x32E</td>
      </tr>
      <tr>
        <td id="L267" class="blob-num js-line-number" data-line-number="267"></td>
        <td id="LC267" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_AGC_CLK_DIVIDE</span>                    0x32F</td>
      </tr>
      <tr>
        <td id="L268" class="blob-num js-line-number" data-line-number="268"></td>
        <td id="LC268" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_INTERRUPT_SOURCE_0</span>                0x336</td>
      </tr>
      <tr>
        <td id="L269" class="blob-num js-line-number" data-line-number="269"></td>
        <td id="LC269" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_INTERRUPT_SOURCE_1</span>                0x337</td>
      </tr>
      <tr>
        <td id="L270" class="blob-num js-line-number" data-line-number="270"></td>
        <td id="LC270" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_CALIBRATION_CONTROL</span>               0x338</td>
      </tr>
      <tr>
        <td id="L271" class="blob-num js-line-number" data-line-number="271"></td>
        <td id="LC271" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_CALIBRATION_STATUS</span>                0x339</td>
      </tr>
      <tr>
        <td id="L272" class="blob-num js-line-number" data-line-number="272"></td>
        <td id="LC272" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_RXBB_CAL_CALWRD_READBACK</span>          0x345</td>
      </tr>
      <tr>
        <td id="L273" class="blob-num js-line-number" data-line-number="273"></td>
        <td id="LC273" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_RXBB_CAL_CALWRD_OVERWRITE</span>         0x346</td>
      </tr>
      <tr>
        <td id="L274" class="blob-num js-line-number" data-line-number="274"></td>
        <td id="LC274" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_RCOSC_CAL_READBACK_HIGH</span>           0x34F</td>
      </tr>
      <tr>
        <td id="L275" class="blob-num js-line-number" data-line-number="275"></td>
        <td id="LC275" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_RCOSC_CAL_READBACK_LOW</span>            0x350</td>
      </tr>
      <tr>
        <td id="L276" class="blob-num js-line-number" data-line-number="276"></td>
        <td id="LC276" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_ADC_CONFIG_LOW</span>                    0x359</td>
      </tr>
      <tr>
        <td id="L277" class="blob-num js-line-number" data-line-number="277"></td>
        <td id="LC277" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_ADC_CONFIG_HIGH</span>                   0x35A</td>
      </tr>
      <tr>
        <td id="L278" class="blob-num js-line-number" data-line-number="278"></td>
        <td id="LC278" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_AGC_OOK_CONTROL</span>                   0x35B</td>
      </tr>
      <tr>
        <td id="L279" class="blob-num js-line-number" data-line-number="279"></td>
        <td id="LC279" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_AGC_CONFIG</span>                        0x35C</td>
      </tr>
      <tr>
        <td id="L280" class="blob-num js-line-number" data-line-number="280"></td>
        <td id="LC280" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_AGC_MODE</span>                          0x35D</td>
      </tr>
      <tr>
        <td id="L281" class="blob-num js-line-number" data-line-number="281"></td>
        <td id="LC281" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_AGC_LOW_THRESHOLD</span>                 0x35E</td>
      </tr>
      <tr>
        <td id="L282" class="blob-num js-line-number" data-line-number="282"></td>
        <td id="LC282" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_AGC_HIGH_THRESHOLD</span>                0x35F</td>
      </tr>
      <tr>
        <td id="L283" class="blob-num js-line-number" data-line-number="283"></td>
        <td id="LC283" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_AGC_GAIN_STATUS</span>                   0x360</td>
      </tr>
      <tr>
        <td id="L284" class="blob-num js-line-number" data-line-number="284"></td>
        <td id="LC284" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_AGC_ADC_WORD</span>                      0x361</td>
      </tr>
      <tr>
        <td id="L285" class="blob-num js-line-number" data-line-number="285"></td>
        <td id="LC285" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_FREQUENCY_ERROR_READBACK</span>          0x372</td>
      </tr>
      <tr>
        <td id="L286" class="blob-num js-line-number" data-line-number="286"></td>
        <td id="LC286" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_VCO_BAND_OVRW_VAL</span>                 0x3CB</td>
      </tr>
      <tr>
        <td id="L287" class="blob-num js-line-number" data-line-number="287"></td>
        <td id="LC287" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_VCO_AMPL_OVRW_VAL</span>                 0x3CC</td>
      </tr>
      <tr>
        <td id="L288" class="blob-num js-line-number" data-line-number="288"></td>
        <td id="LC288" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_VCO_OVRW_EN</span>                       0x3CD</td>
      </tr>
      <tr>
        <td id="L289" class="blob-num js-line-number" data-line-number="289"></td>
        <td id="LC289" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_VCO_CAL_CFG</span>                       0x3D0</td>
      </tr>
      <tr>
        <td id="L290" class="blob-num js-line-number" data-line-number="290"></td>
        <td id="LC290" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_OSC_CONFIG</span>                        0x3D2</td>
      </tr>
      <tr>
        <td id="L291" class="blob-num js-line-number" data-line-number="291"></td>
        <td id="LC291" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_VCO_BAND_READBACK</span>                 0x3DA</td>
      </tr>
      <tr>
        <td id="L292" class="blob-num js-line-number" data-line-number="292"></td>
        <td id="LC292" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_VCO_AMPL_READBACK</span>                 0x3DB</td>
      </tr>
      <tr>
        <td id="L293" class="blob-num js-line-number" data-line-number="293"></td>
        <td id="LC293" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_ANALOG_TEST_BUS</span>                   0x3F8</td>
      </tr>
      <tr>
        <td id="L294" class="blob-num js-line-number" data-line-number="294"></td>
        <td id="LC294" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_RSSI_TSTMUX_SEL</span>                   0x3F9</td>
      </tr>
      <tr>
        <td id="L295" class="blob-num js-line-number" data-line-number="295"></td>
        <td id="LC295" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_GPIO_CONFIGURE</span>                    0x3FA</td>
      </tr>
      <tr>
        <td id="L296" class="blob-num js-line-number" data-line-number="296"></td>
        <td id="LC296" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">MCR_REG_TEST_DAC_GAIN</span>                     0x3FD</td>
      </tr>
      <tr>
        <td id="L297" class="blob-num js-line-number" data-line-number="297"></td>
        <td id="LC297" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L298" class="blob-num js-line-number" data-line-number="298"></td>
        <td id="LC298" class="blob-code js-file-line"><span class="pl-st">struct</span> ADF7023_BBRAM</td>
      </tr>
      <tr>
        <td id="L299" class="blob-num js-line-number" data-line-number="299"></td>
        <td id="LC299" class="blob-code js-file-line">{</td>
      </tr>
      <tr>
        <td id="L300" class="blob-num js-line-number" data-line-number="300"></td>
        <td id="LC300" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> interruptMask0;               <span class="pl-c">// 0x100</span></td>
      </tr>
      <tr>
        <td id="L301" class="blob-num js-line-number" data-line-number="301"></td>
        <td id="LC301" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> interruptMask1;               <span class="pl-c">// 0x101</span></td>
      </tr>
      <tr>
        <td id="L302" class="blob-num js-line-number" data-line-number="302"></td>
        <td id="LC302" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> numberOfWakeups0;             <span class="pl-c">// 0x102</span></td>
      </tr>
      <tr>
        <td id="L303" class="blob-num js-line-number" data-line-number="303"></td>
        <td id="LC303" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> numberOfWakeups1;             <span class="pl-c">// 0x103</span></td>
      </tr>
      <tr>
        <td id="L304" class="blob-num js-line-number" data-line-number="304"></td>
        <td id="LC304" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> numberOfWakeupsIrqThreshold0; <span class="pl-c">// 0x104</span></td>
      </tr>
      <tr>
        <td id="L305" class="blob-num js-line-number" data-line-number="305"></td>
        <td id="LC305" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> numberOfWakeupsIrqThreshold1; <span class="pl-c">// 0x105</span></td>
      </tr>
      <tr>
        <td id="L306" class="blob-num js-line-number" data-line-number="306"></td>
        <td id="LC306" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> rxDwellTime;                  <span class="pl-c">// 0x106</span></td>
      </tr>
      <tr>
        <td id="L307" class="blob-num js-line-number" data-line-number="307"></td>
        <td id="LC307" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> parmtimeDivider;              <span class="pl-c">// 0x107</span></td>
      </tr>
      <tr>
        <td id="L308" class="blob-num js-line-number" data-line-number="308"></td>
        <td id="LC308" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> swmRssiThresh;                <span class="pl-c">// 0x108</span></td>
      </tr>
      <tr>
        <td id="L309" class="blob-num js-line-number" data-line-number="309"></td>
        <td id="LC309" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> channelFreq0;                 <span class="pl-c">// 0x109</span></td>
      </tr>
      <tr>
        <td id="L310" class="blob-num js-line-number" data-line-number="310"></td>
        <td id="LC310" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> channelFreq1;                 <span class="pl-c">// 0x10A</span></td>
      </tr>
      <tr>
        <td id="L311" class="blob-num js-line-number" data-line-number="311"></td>
        <td id="LC311" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> channelFreq2;                 <span class="pl-c">// 0x10B</span></td>
      </tr>
      <tr>
        <td id="L312" class="blob-num js-line-number" data-line-number="312"></td>
        <td id="LC312" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> radioCfg0;                    <span class="pl-c">// 0x10C</span></td>
      </tr>
      <tr>
        <td id="L313" class="blob-num js-line-number" data-line-number="313"></td>
        <td id="LC313" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> radioCfg1;                    <span class="pl-c">// 0x10D</span></td>
      </tr>
      <tr>
        <td id="L314" class="blob-num js-line-number" data-line-number="314"></td>
        <td id="LC314" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> radioCfg2;                    <span class="pl-c">// 0x10E</span></td>
      </tr>
      <tr>
        <td id="L315" class="blob-num js-line-number" data-line-number="315"></td>
        <td id="LC315" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> radioCfg3;                    <span class="pl-c">// 0x10F</span></td>
      </tr>
      <tr>
        <td id="L316" class="blob-num js-line-number" data-line-number="316"></td>
        <td id="LC316" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> radioCfg4;                    <span class="pl-c">// 0x110</span></td>
      </tr>
      <tr>
        <td id="L317" class="blob-num js-line-number" data-line-number="317"></td>
        <td id="LC317" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> radioCfg5;                    <span class="pl-c">// 0x111</span></td>
      </tr>
      <tr>
        <td id="L318" class="blob-num js-line-number" data-line-number="318"></td>
        <td id="LC318" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> radioCfg6;                    <span class="pl-c">// 0x112</span></td>
      </tr>
      <tr>
        <td id="L319" class="blob-num js-line-number" data-line-number="319"></td>
        <td id="LC319" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> radioCfg7;                    <span class="pl-c">// 0x113</span></td>
      </tr>
      <tr>
        <td id="L320" class="blob-num js-line-number" data-line-number="320"></td>
        <td id="LC320" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> radioCfg8;                    <span class="pl-c">// 0x114</span></td>
      </tr>
      <tr>
        <td id="L321" class="blob-num js-line-number" data-line-number="321"></td>
        <td id="LC321" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> radioCfg9;                    <span class="pl-c">// 0x115</span></td>
      </tr>
      <tr>
        <td id="L322" class="blob-num js-line-number" data-line-number="322"></td>
        <td id="LC322" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> radioCfg10;                   <span class="pl-c">// 0x116</span></td>
      </tr>
      <tr>
        <td id="L323" class="blob-num js-line-number" data-line-number="323"></td>
        <td id="LC323" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> radioCfg11;                   <span class="pl-c">// 0x117</span></td>
      </tr>
      <tr>
        <td id="L324" class="blob-num js-line-number" data-line-number="324"></td>
        <td id="LC324" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> imageRejectCalPhase;          <span class="pl-c">// 0x118</span></td>
      </tr>
      <tr>
        <td id="L325" class="blob-num js-line-number" data-line-number="325"></td>
        <td id="LC325" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> imageRejectCalAmplitude;      <span class="pl-c">// 0x119</span></td>
      </tr>
      <tr>
        <td id="L326" class="blob-num js-line-number" data-line-number="326"></td>
        <td id="LC326" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> modeControl;                  <span class="pl-c">// 0x11A</span></td>
      </tr>
      <tr>
        <td id="L327" class="blob-num js-line-number" data-line-number="327"></td>
        <td id="LC327" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> preambleMatch;                <span class="pl-c">// 0x11B</span></td>
      </tr>
      <tr>
        <td id="L328" class="blob-num js-line-number" data-line-number="328"></td>
        <td id="LC328" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> symbolMode;                   <span class="pl-c">// 0x11C</span></td>
      </tr>
      <tr>
        <td id="L329" class="blob-num js-line-number" data-line-number="329"></td>
        <td id="LC329" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> preambleLen;                  <span class="pl-c">// 0x11D</span></td>
      </tr>
      <tr>
        <td id="L330" class="blob-num js-line-number" data-line-number="330"></td>
        <td id="LC330" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> crcPoly0;                     <span class="pl-c">// 0x11E</span></td>
      </tr>
      <tr>
        <td id="L331" class="blob-num js-line-number" data-line-number="331"></td>
        <td id="LC331" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> crcPoly1;                     <span class="pl-c">// 0x11F</span></td>
      </tr>
      <tr>
        <td id="L332" class="blob-num js-line-number" data-line-number="332"></td>
        <td id="LC332" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> syncControl;                  <span class="pl-c">// 0x120</span></td>
      </tr>
      <tr>
        <td id="L333" class="blob-num js-line-number" data-line-number="333"></td>
        <td id="LC333" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> syncByte0;                    <span class="pl-c">// 0x121</span></td>
      </tr>
      <tr>
        <td id="L334" class="blob-num js-line-number" data-line-number="334"></td>
        <td id="LC334" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> syncByte1;                    <span class="pl-c">// 0x122</span></td>
      </tr>
      <tr>
        <td id="L335" class="blob-num js-line-number" data-line-number="335"></td>
        <td id="LC335" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> syncByte2;                    <span class="pl-c">// 0x123</span></td>
      </tr>
      <tr>
        <td id="L336" class="blob-num js-line-number" data-line-number="336"></td>
        <td id="LC336" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> txBaseAdr;                    <span class="pl-c">// 0x124</span></td>
      </tr>
      <tr>
        <td id="L337" class="blob-num js-line-number" data-line-number="337"></td>
        <td id="LC337" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> rxBaseAdr;                    <span class="pl-c">// 0x125</span></td>
      </tr>
      <tr>
        <td id="L338" class="blob-num js-line-number" data-line-number="338"></td>
        <td id="LC338" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> packetLengthControl;          <span class="pl-c">// 0x126</span></td>
      </tr>
      <tr>
        <td id="L339" class="blob-num js-line-number" data-line-number="339"></td>
        <td id="LC339" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> packetLengthMax;              <span class="pl-c">// 0x127</span></td>
      </tr>
      <tr>
        <td id="L340" class="blob-num js-line-number" data-line-number="340"></td>
        <td id="LC340" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> staticRegFix;                 <span class="pl-c">// 0x128</span></td>
      </tr>
      <tr>
        <td id="L341" class="blob-num js-line-number" data-line-number="341"></td>
        <td id="LC341" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> addressMatchOffset;           <span class="pl-c">// 0x129</span></td>
      </tr>
      <tr>
        <td id="L342" class="blob-num js-line-number" data-line-number="342"></td>
        <td id="LC342" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> addressLength;                <span class="pl-c">// 0x12A</span></td>
      </tr>
      <tr>
        <td id="L343" class="blob-num js-line-number" data-line-number="343"></td>
        <td id="LC343" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> addressFiltering0;            <span class="pl-c">// 0x12B</span></td>
      </tr>
      <tr>
        <td id="L344" class="blob-num js-line-number" data-line-number="344"></td>
        <td id="LC344" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> addressFiltering1;            <span class="pl-c">// 0x12C</span></td>
      </tr>
      <tr>
        <td id="L345" class="blob-num js-line-number" data-line-number="345"></td>
        <td id="LC345" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> addressFiltering2;            <span class="pl-c">// 0x12D</span></td>
      </tr>
      <tr>
        <td id="L346" class="blob-num js-line-number" data-line-number="346"></td>
        <td id="LC346" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> addressFiltering3;            <span class="pl-c">// 0x12E</span></td>
      </tr>
      <tr>
        <td id="L347" class="blob-num js-line-number" data-line-number="347"></td>
        <td id="LC347" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> addressFiltering4;            <span class="pl-c">// 0x12F</span></td>
      </tr>
      <tr>
        <td id="L348" class="blob-num js-line-number" data-line-number="348"></td>
        <td id="LC348" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> addressFiltering5;            <span class="pl-c">// 0x130</span></td>
      </tr>
      <tr>
        <td id="L349" class="blob-num js-line-number" data-line-number="349"></td>
        <td id="LC349" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> addressFiltering6;            <span class="pl-c">// 0x131</span></td>
      </tr>
      <tr>
        <td id="L350" class="blob-num js-line-number" data-line-number="350"></td>
        <td id="LC350" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> addressFiltering7;            <span class="pl-c">// 0x132</span></td>
      </tr>
      <tr>
        <td id="L351" class="blob-num js-line-number" data-line-number="351"></td>
        <td id="LC351" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> addressFiltering8;            <span class="pl-c">// 0x133</span></td>
      </tr>
      <tr>
        <td id="L352" class="blob-num js-line-number" data-line-number="352"></td>
        <td id="LC352" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> addressFiltering9;            <span class="pl-c">// 0x134</span></td>
      </tr>
      <tr>
        <td id="L353" class="blob-num js-line-number" data-line-number="353"></td>
        <td id="LC353" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> addressFiltering10;           <span class="pl-c">// 0x135</span></td>
      </tr>
      <tr>
        <td id="L354" class="blob-num js-line-number" data-line-number="354"></td>
        <td id="LC354" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> addressFiltering11;           <span class="pl-c">// 0x136</span></td>
      </tr>
      <tr>
        <td id="L355" class="blob-num js-line-number" data-line-number="355"></td>
        <td id="LC355" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> addressFiltering12;           <span class="pl-c">// 0x137</span></td>
      </tr>
      <tr>
        <td id="L356" class="blob-num js-line-number" data-line-number="356"></td>
        <td id="LC356" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> rssiWaitTime;                 <span class="pl-c">// 0x138</span></td>
      </tr>
      <tr>
        <td id="L357" class="blob-num js-line-number" data-line-number="357"></td>
        <td id="LC357" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> testmodes;                    <span class="pl-c">// 0x139</span></td>
      </tr>
      <tr>
        <td id="L358" class="blob-num js-line-number" data-line-number="358"></td>
        <td id="LC358" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> transitionClockDiv;           <span class="pl-c">// 0x13A</span></td>
      </tr>
      <tr>
        <td id="L359" class="blob-num js-line-number" data-line-number="359"></td>
        <td id="LC359" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> reserved0;                    <span class="pl-c">// 0x13B</span></td>
      </tr>
      <tr>
        <td id="L360" class="blob-num js-line-number" data-line-number="360"></td>
        <td id="LC360" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> reserved1;                    <span class="pl-c">// 0x13C</span></td>
      </tr>
      <tr>
        <td id="L361" class="blob-num js-line-number" data-line-number="361"></td>
        <td id="LC361" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> reserved2;                    <span class="pl-c">// 0x13D</span></td>
      </tr>
      <tr>
        <td id="L362" class="blob-num js-line-number" data-line-number="362"></td>
        <td id="LC362" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> rxSynthLockTime;              <span class="pl-c">// 0x13E</span></td>
      </tr>
      <tr>
        <td id="L363" class="blob-num js-line-number" data-line-number="363"></td>
        <td id="LC363" class="blob-code js-file-line">    <span class="pl-st">unsigned</span> <span class="pl-st">char</span> txSynthLockTime;              <span class="pl-c">// 0x13F</span></td>
      </tr>
      <tr>
        <td id="L364" class="blob-num js-line-number" data-line-number="364"></td>
        <td id="LC364" class="blob-code js-file-line">};</td>
      </tr>
      <tr>
        <td id="L365" class="blob-num js-line-number" data-line-number="365"></td>
        <td id="LC365" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L366" class="blob-num js-line-number" data-line-number="366"></td>
        <td id="LC366" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">ADF7023_TX_BASE_ADR</span> 0x10</td>
      </tr>
      <tr>
        <td id="L367" class="blob-num js-line-number" data-line-number="367"></td>
        <td id="LC367" class="blob-code js-file-line">#<span class="pl-k">define</span> <span class="pl-en">ADF7023_RX_BASE_ADR</span> 0x10</td>
      </tr>
      <tr>
        <td id="L368" class="blob-num js-line-number" data-line-number="368"></td>
        <td id="LC368" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L369" class="blob-num js-line-number" data-line-number="369"></td>
        <td id="LC369" class="blob-code js-file-line"><span class="pl-c">/******************************************************************************/</span></td>
      </tr>
      <tr>
        <td id="L370" class="blob-num js-line-number" data-line-number="370"></td>
        <td id="LC370" class="blob-code js-file-line"><span class="pl-c">/************************ Functions Declarations ******************************/</span></td>
      </tr>
      <tr>
        <td id="L371" class="blob-num js-line-number" data-line-number="371"></td>
        <td id="LC371" class="blob-code js-file-line"><span class="pl-c">/******************************************************************************/</span></td>
      </tr>
      <tr>
        <td id="L372" class="blob-num js-line-number" data-line-number="372"></td>
        <td id="LC372" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L373" class="blob-num js-line-number" data-line-number="373"></td>
        <td id="LC373" class="blob-code js-file-line"><span class="pl-c">/* Initializes the ADF7023. */</span></td>
      </tr>
      <tr>
        <td id="L374" class="blob-num js-line-number" data-line-number="374"></td>
        <td id="LC374" class="blob-code js-file-line"><span class="pl-st">char</span> <span class="pl-en">ADF7023_Init</span>(<span class="pl-st">void</span>);</td>
      </tr>
      <tr>
        <td id="L375" class="blob-num js-line-number" data-line-number="375"></td>
        <td id="LC375" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L376" class="blob-num js-line-number" data-line-number="376"></td>
        <td id="LC376" class="blob-code js-file-line"><span class="pl-c">/* Reads the status word of the ADF7023. */</span></td>
      </tr>
      <tr>
        <td id="L377" class="blob-num js-line-number" data-line-number="377"></td>
        <td id="LC377" class="blob-code js-file-line"><span class="pl-st">void</span> <span class="pl-en">ADF7023_GetStatus</span>(<span class="pl-st">unsigned</span> <span class="pl-st">char</span>* status);</td>
      </tr>
      <tr>
        <td id="L378" class="blob-num js-line-number" data-line-number="378"></td>
        <td id="LC378" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L379" class="blob-num js-line-number" data-line-number="379"></td>
        <td id="LC379" class="blob-code js-file-line"><span class="pl-c">/* Initiates a command. */</span></td>
      </tr>
      <tr>
        <td id="L380" class="blob-num js-line-number" data-line-number="380"></td>
        <td id="LC380" class="blob-code js-file-line"><span class="pl-st">void</span> <span class="pl-en">ADF7023_SetCommand</span>(<span class="pl-st">unsigned</span> <span class="pl-st">char</span> command);</td>
      </tr>
      <tr>
        <td id="L381" class="blob-num js-line-number" data-line-number="381"></td>
        <td id="LC381" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L382" class="blob-num js-line-number" data-line-number="382"></td>
        <td id="LC382" class="blob-code js-file-line"><span class="pl-c">/* Sets a FW state and waits until the device enters in that state. */</span></td>
      </tr>
      <tr>
        <td id="L383" class="blob-num js-line-number" data-line-number="383"></td>
        <td id="LC383" class="blob-code js-file-line"><span class="pl-st">void</span> <span class="pl-en">ADF7023_SetFwState</span>(<span class="pl-st">unsigned</span> <span class="pl-st">char</span> fwState);</td>
      </tr>
      <tr>
        <td id="L384" class="blob-num js-line-number" data-line-number="384"></td>
        <td id="LC384" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L385" class="blob-num js-line-number" data-line-number="385"></td>
        <td id="LC385" class="blob-code js-file-line"><span class="pl-c">/* Reads data from the RAM. */</span></td>
      </tr>
      <tr>
        <td id="L386" class="blob-num js-line-number" data-line-number="386"></td>
        <td id="LC386" class="blob-code js-file-line"><span class="pl-st">void</span> <span class="pl-en">ADF7023_GetRAM</span>(<span class="pl-st">unsigned</span> <span class="pl-st">long</span> address,</td>
      </tr>
      <tr>
        <td id="L387" class="blob-num js-line-number" data-line-number="387"></td>
        <td id="LC387" class="blob-code js-file-line">                    <span class="pl-st">unsigned</span> <span class="pl-st">long</span> length,</td>
      </tr>
      <tr>
        <td id="L388" class="blob-num js-line-number" data-line-number="388"></td>
        <td id="LC388" class="blob-code js-file-line">                    <span class="pl-st">unsigned</span> <span class="pl-st">char</span>* data);</td>
      </tr>
      <tr>
        <td id="L389" class="blob-num js-line-number" data-line-number="389"></td>
        <td id="LC389" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L390" class="blob-num js-line-number" data-line-number="390"></td>
        <td id="LC390" class="blob-code js-file-line"><span class="pl-c">/* Writes data to RAM. */</span></td>
      </tr>
      <tr>
        <td id="L391" class="blob-num js-line-number" data-line-number="391"></td>
        <td id="LC391" class="blob-code js-file-line"><span class="pl-st">void</span> <span class="pl-en">ADF7023_SetRAM</span>(<span class="pl-st">unsigned</span> <span class="pl-st">long</span> address,</td>
      </tr>
      <tr>
        <td id="L392" class="blob-num js-line-number" data-line-number="392"></td>
        <td id="LC392" class="blob-code js-file-line">                    <span class="pl-st">unsigned</span> <span class="pl-st">long</span> length,</td>
      </tr>
      <tr>
        <td id="L393" class="blob-num js-line-number" data-line-number="393"></td>
        <td id="LC393" class="blob-code js-file-line">                    <span class="pl-st">unsigned</span> <span class="pl-st">char</span>* data);</td>
      </tr>
      <tr>
        <td id="L394" class="blob-num js-line-number" data-line-number="394"></td>
        <td id="LC394" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L395" class="blob-num js-line-number" data-line-number="395"></td>
        <td id="LC395" class="blob-code js-file-line"><span class="pl-c">/* Receives one packet. */</span></td>
      </tr>
      <tr>
        <td id="L396" class="blob-num js-line-number" data-line-number="396"></td>
        <td id="LC396" class="blob-code js-file-line"><span class="pl-st">void</span> <span class="pl-en">ADF7023_ReceivePacket</span>(<span class="pl-st">unsigned</span> <span class="pl-st">char</span>* packet, <span class="pl-st">unsigned</span> <span class="pl-st">char</span>* length);</td>
      </tr>
      <tr>
        <td id="L397" class="blob-num js-line-number" data-line-number="397"></td>
        <td id="LC397" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L398" class="blob-num js-line-number" data-line-number="398"></td>
        <td id="LC398" class="blob-code js-file-line"><span class="pl-c">/* Transmits one packet. */</span></td>
      </tr>
      <tr>
        <td id="L399" class="blob-num js-line-number" data-line-number="399"></td>
        <td id="LC399" class="blob-code js-file-line"><span class="pl-st">void</span> <span class="pl-en">ADF7023_TransmitPacket</span>(<span class="pl-st">unsigned</span> <span class="pl-st">char</span>* packet, <span class="pl-st">unsigned</span> <span class="pl-st">char</span> length);</td>
      </tr>
      <tr>
        <td id="L400" class="blob-num js-line-number" data-line-number="400"></td>
        <td id="LC400" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L401" class="blob-num js-line-number" data-line-number="401"></td>
        <td id="LC401" class="blob-code js-file-line"><span class="pl-c">/* Sets the channel frequency. */</span></td>
      </tr>
      <tr>
        <td id="L402" class="blob-num js-line-number" data-line-number="402"></td>
        <td id="LC402" class="blob-code js-file-line"><span class="pl-st">void</span> <span class="pl-en">ADF7023_SetChannelFrequency</span>(<span class="pl-st">unsigned</span> <span class="pl-st">long</span> chFreq);</td>
      </tr>
      <tr>
        <td id="L403" class="blob-num js-line-number" data-line-number="403"></td>
        <td id="LC403" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L404" class="blob-num js-line-number" data-line-number="404"></td>
        <td id="LC404" class="blob-code js-file-line"><span class="pl-c">/* Sets the data rate. */</span></td>
      </tr>
      <tr>
        <td id="L405" class="blob-num js-line-number" data-line-number="405"></td>
        <td id="LC405" class="blob-code js-file-line"><span class="pl-st">void</span> <span class="pl-en">ADF7023_SetDataRate</span>(<span class="pl-st">unsigned</span> <span class="pl-st">long</span> dataRate);</td>
      </tr>
      <tr>
        <td id="L406" class="blob-num js-line-number" data-line-number="406"></td>
        <td id="LC406" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L407" class="blob-num js-line-number" data-line-number="407"></td>
        <td id="LC407" class="blob-code js-file-line"><span class="pl-c">/* Sets the frequency deviation. */</span></td>
      </tr>
      <tr>
        <td id="L408" class="blob-num js-line-number" data-line-number="408"></td>
        <td id="LC408" class="blob-code js-file-line"><span class="pl-st">void</span> <span class="pl-en">ADF7023_SetFrequencyDeviation</span>(<span class="pl-st">unsigned</span> <span class="pl-st">long</span> freqDev);</td>
      </tr>
      <tr>
        <td id="L409" class="blob-num js-line-number" data-line-number="409"></td>
        <td id="LC409" class="blob-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L410" class="blob-num js-line-number" data-line-number="410"></td>
        <td id="LC410" class="blob-code js-file-line">#<span class="pl-k">endif</span> <span class="pl-c">// __ADF7023_H__</span></td>
      </tr>
</table>

  </div>

  </div>
</div>

<a href="#jump-to-line" rel="facebox[.linejump]" data-hotkey="l" style="display:none">Jump to Line</a>
<div id="jump-to-line" style="display:none">
  <form accept-charset="UTF-8" class="js-jump-to-line-form">
    <input class="linejump-input js-jump-to-line-field" type="text" placeholder="Jump to line&hellip;" autofocus>
    <button type="submit" class="button">Go</button>
  </form>
</div>

        </div>

      </div><!-- /.repo-container -->
      <div class="modal-backdrop"></div>
    </div><!-- /.container -->
  </div><!-- /.site -->


    </div><!-- /.wrapper -->

      <div class="container">
  <div class="site-footer" role="contentinfo">
    <ul class="site-footer-links right">
      <li><a href="https://status.github.com/">Status</a></li>
      <li><a href="https://developer.github.com">API</a></li>
      <li><a href="http://training.github.com">Training</a></li>
      <li><a href="http://shop.github.com">Shop</a></li>
      <li><a href="/blog">Blog</a></li>
      <li><a href="/about">About</a></li>

    </ul>

    <a href="/" aria-label="Homepage">
      <span class="mega-octicon octicon-mark-github" title="GitHub"></span>
    </a>

    <ul class="site-footer-links">
      <li>&copy; 2014 <span title="0.04630s from github-fe138-cp1-prd.iad.github.net">GitHub</span>, Inc.</li>
        <li><a href="/site/terms">Terms</a></li>
        <li><a href="/site/privacy">Privacy</a></li>
        <li><a href="/security">Security</a></li>
        <li><a href="/contact">Contact</a></li>
    </ul>
  </div><!-- /.site-footer -->
</div><!-- /.container -->


    <div class="fullscreen-overlay js-fullscreen-overlay" id="fullscreen_overlay">
  <div class="fullscreen-container js-suggester-container">
    <div class="textarea-wrap">
      <textarea name="fullscreen-contents" id="fullscreen-contents" class="fullscreen-contents js-fullscreen-contents js-suggester-field" placeholder=""></textarea>
    </div>
  </div>
  <div class="fullscreen-sidebar">
    <a href="#" class="exit-fullscreen js-exit-fullscreen tooltipped tooltipped-w" aria-label="Exit Zen Mode">
      <span class="mega-octicon octicon-screen-normal"></span>
    </a>
    <a href="#" class="theme-switcher js-theme-switcher tooltipped tooltipped-w"
      aria-label="Switch themes">
      <span class="octicon octicon-color-mode"></span>
    </a>
  </div>
</div>



    <div id="ajax-error-message" class="flash flash-error">
      <span class="octicon octicon-alert"></span>
      <a href="#" class="octicon octicon-x flash-close js-ajax-error-dismiss" aria-label="Dismiss error"></a>
      Something went wrong with that request. Please try again.
    </div>


      <script crossorigin="anonymous" src="https://assets-cdn.github.com/assets/frameworks-2d727fed4d969b14b28165c75ad12d7dddd56c0198fa70cedc3fdad7ac395b2c.js" type="text/javascript"></script>
      <script async="async" crossorigin="anonymous" src="https://assets-cdn.github.com/assets/github-df890fda784aa4e11f79ebb77d324afca1b2ce38f543eb8e247f9213825b11b4.js" type="text/javascript"></script>
      
      
  </body>
</html>

