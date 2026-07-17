---
layout: default
title: Writing
permalink: /writing/
---

<div class="home">

  <h1 class="page-heading">Writing</h1>
  <p class="page-intro">Notes on production software, modern C++, APIs, build systems, architecture, and the engineering trade-offs around them.</p>

  <ul class="post-list">
    {% for post in site.posts %}
      <li>
        <span class="post-meta">{{ post.date | date: "%b %-d, %Y" }}</span>
        <h4>
          <a class="post-link" href="{{ post.url | relative_url }}">{{ post.title }}</a>
        </h4>
        <hr>
      </li>
    {% endfor %}
  </ul>

</div>
