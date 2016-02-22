# Cookie Choices

Drupal 7 module that makes a website compliant with the European Commission's cookies reglementation. Uses Google's [cookiechoices](https://www.cookiechoices.org/#resources).

Provides fine grained layout options that are not part of modules like [EU Cookie Compliance](https://www.drupal.org/project/eu_cookie_compliances) or [Cookie Control] (https://www.drupal.org/project/cookiecontrol).

## Installation

This module is not yet part of Drupal.org projects, so it should be installed under the custom directory.

```
cd sites/all/modules/custom
git clone git@github.com:tiltfactory/cookiechoices.git
drush en cookiechoices
```

Remove .git directory in the module to sync it via the main repo.

Optional configuration (light or dark theme, text and link) at admin/config/user-interface/cookiechoices/settings.
