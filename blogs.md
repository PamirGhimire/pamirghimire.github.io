---
layout: default
title: Blogs
permalink: /blogs/
---

<div class="home">

  <h1 class="page-heading">Blogs</h1>

  <ul class="post-list">
    {% for post in site.posts %}
      <li>
        <span class="post-meta">{{ post.date | date: "%b %-d, %Y" }}</span>
        <h4>
          <a class="post-link" href="{{ post.url | prepend: site.baseurl }}">{{ post.title }}</a>
        </h4>
        <hr>
      </li>
    {% endfor %}
  </ul>

</div>